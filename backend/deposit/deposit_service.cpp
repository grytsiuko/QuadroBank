

#include <backend/utils/time_intervals.h>
#include <backend/db/specifications/deposits_by_card_number_specification.h>
#include <backend/db/specifications/deposit_variants_all_specification.h>
#include <backend/db/specifications/deposits_before_time_specification.h>
#include <backend/utils/exceptions/unauthorized_exception.h>
#include <backend/utils/exceptions/not_enough_money_exception.h>
#include <backend/utils/exceptions/deposit_for_credit_exception.h>
#include <backend/utils/exceptions/illegal_percentage_exception.h>
#include <backend/utils/exceptions/non_positive_number_exception.h>
#include "deposit_service.h"

vector<DepositDto> DepositService::get_all_by_user(const TokenDto &token_dto) const {
    const string card_number = _token_service.get_card_number(token_dto._token);
    Account account = _auth_service.assert_account(card_number);


    const vector<Deposit> deposits = _deposit_repository.get_list(
            DepositsByCardNumberSpecification(account._card_number));

    vector<DepositDto> deposit_dtos;

    deposit_dtos.reserve(deposits.size());
    for (const Deposit &d : deposits) {
        deposit_dtos.push_back(DepositDto{d._id, d._period_sec, d._start_date, d._end_date, d._percentage, d._sum});
    }

    return deposit_dtos;
}

vector<DepositVariantDto> DepositService::get_possible_variants(const TokenDto &token_dto) const {
    if (_account_repository.get_by_card_number(_token_service.get_card_number(token_dto._token)).is_empty()) {
        throw UnauthorizedException();
    }
    vector<DepositVariant> deposit_variants = _deposit_variant_repository.get_list(
            DepositVariantsAllSpecification());
    vector<DepositVariantDto> possible_variants;
    possible_variants.reserve(deposit_variants.size());
    for (DepositVariant &dep_var : deposit_variants) {
        possible_variants.push_back(DepositVariantDto{dep_var._period_sec, dep_var._percentage});
    }
    return possible_variants;
}

void DepositService::add(const DepositCreateDto &deposit_create_dto) const {
    const string card_number = _token_service.get_card_number(deposit_create_dto._token);
    Account account = _auth_service.assert_account(card_number);
    User user = _auth_service.assert_user(account._user_id);

    if (account._credit_limit != 0) {
        throw DepositForCreditException();
    }
    const Optional<DepositVariant> optional_deposit_variant = _deposit_variant_repository.get_by_percentage(
            deposit_create_dto._percentage);

    if (optional_deposit_variant.is_empty()) {
        throw IllegalPercentageException();
    }
    if (deposit_create_dto._sum <= 0) {
        throw NonPositiveNumberException();
    }
    if (account._balance < deposit_create_dto._sum) {
        throw NotEnoughMoneyException();
    }

    const DepositVariant &deposit_variant = optional_deposit_variant.get();
    const time_t currDate = time(nullptr);
    Deposit deposit{0, card_number, deposit_create_dto._percentage, deposit_variant._period_sec, currDate,
                    currDate + deposit_variant._period_sec, deposit_create_dto._sum};

    _account_service.change_balance(account, - deposit_create_dto._sum);

    _deposit_repository.add(deposit);
    _notification_service.notify(user, account, "You have created deposit");
}

vector<Deposit> DepositService::get_to_be_paid() const {
    time_t current_time = time(nullptr);
    return _deposit_repository.get_list(DepositsBeforeTimeSpecification(current_time));
}


void DepositService::return_finished(const Deposit &deposit) const {
    Account account = _auth_service.assert_account(deposit._account_card_number);
    User user = _auth_service.assert_user(account._user_id);

    _account_service.change_balance(account, deposit._sum + floor(deposit._sum * deposit._percentage));
    _deposit_repository.remove(deposit._id);

    _notification_service.notify(user, account, "Your deposit has been returned");
}



