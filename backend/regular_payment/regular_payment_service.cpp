
#include <ctime>
#include "regular_payment_service.h"
#include "backend/utils/exception.h"

vector<RegularPaymentDto> RegularPaymentService::get_all_by_user(const TokenDto &token_dto) const {
    const Account account = _get_account(token_dto._token);

    const vector<RegularPayment> regular_payments = _regular_payment_repository.get_list(Specification<RegularPayment>([&](const RegularPayment &rp) {
        return account._card_number == rp._account_card;
    }));

    vector<RegularPaymentDto> regular_payments_dtos;

    regular_payments_dtos.reserve(regular_payments.size());
    for (const RegularPayment& rp : regular_payments) {
        regular_payments_dtos.push_back(RegularPaymentDto{rp._id, rp._period_sec, rp._target_card, rp._sum});
    }

    return regular_payments_dtos;
}

void RegularPaymentService::add(const RegularPaymentCreateDto &regular_payment_create_dto) const {
    const Account account = _get_account(regular_payment_create_dto._token);
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

}

void RegularPaymentService::update(const RegularPaymentUpdateDto &regular_payment_update_dto) const {
    const Account account = _get_account(regular_payment_update_dto._token);
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
}

void RegularPaymentService::remove(const RegularPaymentDeleteDto &regular_payment_delete_dto) const {
    const Account account = _get_account(regular_payment_delete_dto._token);
    Optional<RegularPayment> optional_payment = _regular_payment_repository.get_by_id(regular_payment_delete_dto._payment_id);
    if(optional_payment.is_empty()){
        throw Exception("Regular payment does not exists");
    }

    if(account._card_number != optional_payment.get()._account_card){
        throw Exception("Attempt to delete someone else's regular payment");
    }

    _regular_payment_repository.remove(regular_payment_delete_dto._payment_id);
}


vector<RegularPayment> RegularPaymentService::get_to_be_paid() const {
    time_t current_time = time(nullptr);
    return _regular_payment_repository.get_list(Specification<RegularPayment>(
            [&](const RegularPayment& rp){return rp._next_time <= current_time;}
            ));
}

Account RegularPaymentService::_get_account(const string &token) const {
    const string card_number = _token_service.get_card_number(token);
    const Optional<Account> optional_account = _account_repository.get_by_card_number(card_number);
    if (optional_account.is_empty()) {
        throw Exception("Illegal token");
    }

    return optional_account.get();
}

void RegularPaymentService::pay(RegularPayment regular_payment) const {
    Optional<Account> optional_from = _account_repository.get_by_card_number(regular_payment._account_card);
    Optional<Account> optional_to = _account_repository.get_by_card_number(regular_payment._target_card);
    if(optional_from.is_empty() || optional_to.is_empty()){
        throw Exception("Internal error");
    }

    Account from_account = optional_from.get();
    Account to_account = optional_to.get();

    if(from_account._balance + from_account._credit_limit < regular_payment._sum){
        //todo notify
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
}
