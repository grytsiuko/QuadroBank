
#include <ctime>
#include "regular_payment_service.h"
#include "backend/utils/exception.h"

vector<RegularPaymentDto> RegularPaymentService::get_all_by_user(const TokenDto &token_dto) const {
    const Account account = *_get_account(token_dto._token);

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
    const Account* account = _get_account(regular_payment_create_dto._token);
    _regular_payment_repository.add(RegularPayment{0,
                                                   account->_card_number,
                                                   regular_payment_create_dto._period_sec,
                                                   regular_payment_create_dto._target_card,
                                                   regular_payment_create_dto._next_time - regular_payment_create_dto._period_sec,
                                                   regular_payment_create_dto._sum});

}

void RegularPaymentService::update(const RegularPaymentUpdateDto &regular_payment_update_dto) const {
    const Account* account = _get_account(regular_payment_update_dto._token);
    _regular_payment_repository.update(RegularPayment{regular_payment_update_dto._payment_id,
                                                      account->_card_number,
                                                      regular_payment_update_dto._period_sec,
                                                      regular_payment_update_dto._target_card,
                                                      regular_payment_update_dto._next_time - regular_payment_update_dto._period_sec,
                                                      regular_payment_update_dto._sum
                                                      });
}

void RegularPaymentService::remove(const RegularPaymentDeleteDto &regular_payment_delete_dto) const {
    _get_account(regular_payment_delete_dto._token);
    _regular_payment_repository.remove(regular_payment_delete_dto._payment_id);
}


vector<RegularPayment> RegularPaymentService::get_to_be_paid() const {
    time_t current_time = time(nullptr);
    return _regular_payment_repository.get_list(Specification<RegularPayment>(
            [&](const RegularPayment& rp){return rp._last_paid + rp._period_sec <= current_time;}
            ));
}

const Account *RegularPaymentService::_get_account(const string &token) const {
    const string card_number = _token_service.get_card_number(token);
    const Optional<Account> optional_account = _account_repository.get_by_card_number(card_number);
    if (optional_account.is_empty()) {
        throw Exception("Illegal token");
    }

    return optional_account.get();
}