
#include <ctime>
#include "regular_payment_service.h"
#include "backend/utils/exception.h"


RegularPaymentDto RegularPaymentService::get_by_id(const RegularPaymentGetDto &get_dto) const {
    string card_number = _token_service.get_card_number(get_dto._token);
    Account account = _auth_service.assert_account(card_number);

    Optional<RegularPayment> optional_rp = _regular_payment_repository.get_by_id(get_dto._id);

    if(optional_rp.is_empty()){
        throw Exception("Regular payment with this id does not exists");
    }

    RegularPayment rp = optional_rp.get();

    return RegularPaymentDto{
        rp._id,
        rp._period_sec,
        rp._target_card,
        rp._sum,
        rp._next_time
    };

}


vector<RegularPaymentDto> RegularPaymentService::get_all_by_user(const TokenDto &token_dto) const {
    string card_number = _token_service.get_card_number(token_dto._token);
    Account account = _auth_service.assert_account(card_number);

    const vector<RegularPayment> regular_payments = _regular_payment_repository.get_list(Specification<RegularPayment>(
            [&](const RegularPayment &rp) {
                return account._card_number == rp._account_card;
            },
            "account_card=%0",
            {"'" + account._card_number + "'"}
    ));

    vector<RegularPaymentDto> regular_payments_dtos;

    regular_payments_dtos.reserve(regular_payments.size());
    for (const RegularPayment& rp : regular_payments) {
        regular_payments_dtos.push_back(RegularPaymentDto{rp._id, rp._period_sec, rp._target_card, rp._sum, rp._next_time});
    }

    return regular_payments_dtos;
}

void RegularPaymentService::add(const RegularPaymentCreateDto &regular_payment_create_dto) const {
    string card_number = _token_service.get_card_number(regular_payment_create_dto._token);
    Account account = _auth_service.assert_account(card_number);
    User user = _auth_service.assert_user(account._user_id);

    time_t current_time = time(nullptr);

    if(regular_payment_create_dto._target_card == account._card_number){
        throw Exception("Unable to create regular payment to the same account");
    }

    if(regular_payment_create_dto._next_time <= current_time){
        throw Exception("Next payment should be in the future");
    }

    if(regular_payment_create_dto._period_sec <= 0){
        throw Exception("Period should be positive");
    }

    Optional<Account> optional_account = _account_repository.get_by_card_number(regular_payment_create_dto._target_card);
    if(optional_account.is_empty()){
        throw Exception("Target account does not exists");
    }

    if(regular_payment_create_dto._sum <= 0){
        throw Exception("Sum should be positive");
    }

    _regular_payment_repository.add(RegularPayment{0,
                                                   account._card_number,
                                                   regular_payment_create_dto._period_sec,
                                                   regular_payment_create_dto._target_card,
                                                   regular_payment_create_dto._next_time,
                                                   regular_payment_create_dto._sum});
    _notification_service.notify(user, account, "You have created regular payment");
}

void RegularPaymentService::update(const RegularPaymentUpdateDto &regular_payment_update_dto) const {
    string card_number = _token_service.get_card_number(regular_payment_update_dto._token);
    Account account = _auth_service.assert_account(card_number);
    User user = _auth_service.assert_user(account._user_id);

    time_t current_time = time(nullptr);

    Optional<RegularPayment> optional_payment = _regular_payment_repository.get_by_id(regular_payment_update_dto._payment_id);
    if(optional_payment.is_empty()){
        throw Exception("Attempt to change non-existent regular payment");
    }

    if(regular_payment_update_dto._target_card == account._card_number){
        throw Exception("Unable to create regular payment to the same account");
    }

    if(regular_payment_update_dto._next_time <= current_time){
        throw Exception("Next payment should be in the future");
    }

    if(regular_payment_update_dto._period_sec <= 0){
        throw Exception("Period should be positive");
    }

    Optional<Account> optional_account = _account_repository.get_by_card_number(regular_payment_update_dto._target_card);
    if(optional_account.is_empty()){
        throw Exception("Target account does not exists");
    }

    if(regular_payment_update_dto._sum <= 0){
        throw Exception("Sum should be positive");
    }

    _regular_payment_repository.update(RegularPayment{regular_payment_update_dto._payment_id,
                                                      account._card_number,
                                                      regular_payment_update_dto._period_sec,
                                                      regular_payment_update_dto._target_card,
                                                      regular_payment_update_dto._next_time,
                                                      regular_payment_update_dto._sum
                                                      });
    _notification_service.notify(user, account, "You have updated regular payment");
}

void RegularPaymentService::remove(const RegularPaymentDeleteDto &regular_payment_delete_dto) const {
    string card_number = _token_service.get_card_number(regular_payment_delete_dto._token);
    Account account = _auth_service.assert_account(card_number);
    User user = _auth_service.assert_user(account._user_id);

    Optional<RegularPayment> optional_payment = _regular_payment_repository.get_by_id(regular_payment_delete_dto._payment_id);
    if(optional_payment.is_empty()){
        throw Exception("Regular payment does not exists");
    }

    if(account._card_number != optional_payment.get()._account_card){
        throw Exception("Attempt to delete someone else's regular payment");
    }

    _regular_payment_repository.remove(regular_payment_delete_dto._payment_id);
    _notification_service.notify(user, account, "You have deleted regular payment");
}


vector<RegularPayment> RegularPaymentService::get_to_be_paid() const {
    time_t current_time = time(nullptr);
    return _regular_payment_repository.get_list(Specification<RegularPayment>(
            [&](const RegularPayment& rp){return rp._next_time <= current_time;},
            "next_time<%0",
            {std::to_string(current_time)}
    ));
}

void RegularPaymentService::pay(RegularPayment regular_payment) const {
    Account from_account = _auth_service.assert_account(regular_payment._account_card);
    User from_user = _auth_service.assert_user(from_account._user_id);
    Account to_account = _auth_service.assert_account(regular_payment._target_card);
    User to_user = _auth_service.assert_user(to_account._user_id);

    if(from_account._balance + from_account._credit_limit < regular_payment._sum){
        _notification_service.notify(from_user, from_account, "Not enough money, deleting regular payment");
        int removed = _regular_payment_repository.remove(regular_payment._id);
        if(removed == 0){
            throw Exception("Internal error");
        }
        return;
    }

    from_account._balance -= regular_payment._sum;
    to_account._balance += regular_payment._sum;

    _account_repository.update(from_account);
    _account_repository.update(to_account);

    regular_payment._next_time += regular_payment._period_sec;
    int updated = _regular_payment_repository.update(regular_payment);
    if(updated == 0){
        throw Exception("Internal error");
    }

    _notification_service.notify(from_user, from_account, "Regular payment from your account performed");
    _notification_service.notify(to_user, to_account, "Regular payment to your account performed");

    if (regular_payment._next_time <= time(nullptr)) {
        pay(regular_payment);
    }
}
