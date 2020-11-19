
#include <backend/db/specifications/accounts_debtor_at_time_specification.h>
#include <backend/utils/exceptions/blocked_card_exception.h>
#include <backend/utils/exceptions/illegal_pin_exception.h>
#include <backend/utils/exceptions/same_account_exception.h>
#include <backend/utils/exceptions/non_positive_number_exception.h>
#include <backend/utils/exceptions/simple_card_balance_exception.h>
#include <backend/utils/exceptions/credit_card_balance_exception.h>
#include "account_service.h"

SessionDto AccountService::authorize(const AccountAuthorizeDto &account_authorize_dto) const {
    Account account = _auth_service.assert_account(account_authorize_dto._card_number);
    User user = _auth_service.assert_user(account._user_id);

    if(account._is_blocked){
        throw BlockedCardException();
    }

    if (account._pin != account_authorize_dto._pin) {
        _incorrect_pins[account_authorize_dto._card_number] += 1;

        if(_incorrect_pins[account_authorize_dto._card_number] >= MAX_INCORRECT_PINS){
            account._is_blocked = true;
            _account_repository.update(account);
        }

        throw IllegalPinException();
    }

    _incorrect_pins.erase(account_authorize_dto._card_number);

    return SessionDto{_token_service.generate_token(account), user._name};
}

AccountBalanceDto AccountService::check_balance(const TokenDto &token_dto) const {
    string card_number = _token_service.get_card_number(token_dto._token);
    Account account = _auth_service.assert_account(card_number);

    return AccountBalanceDto(account);
}

void AccountService::top_up(const AccountUpdateDto &account_update_dto) const {
    _assert_positive_sum(account_update_dto._sum);

    string card_number = _token_service.get_card_number(account_update_dto._token);
    Account account = _auth_service.assert_account(card_number);
    User user = _auth_service.assert_user(account._user_id);

    change_balance(account, account_update_dto._sum);

    _notification_service.notify(user, account, "Top up performed");
}

void AccountService::withdraw(const AccountUpdateDto &account_update_dto) const {
    _assert_positive_sum(account_update_dto._sum);

    string card_number = _token_service.get_card_number(account_update_dto._token);
    Account account = _auth_service.assert_account(card_number);
    User user = _auth_service.assert_user(account._user_id);

    change_balance(account, - account_update_dto._sum);

    _notification_service.notify(user, account, "Withdraw performed");
}

void AccountService::transfer(const AccountTransferDto &account_transfer_dto) const {
    _assert_positive_sum(account_transfer_dto._sum);

    string card_number = _token_service.get_card_number(account_transfer_dto._token);
    Account account = _auth_service.assert_account(card_number);
    User user = _auth_service.assert_user(account._user_id);

    Account target_account = _auth_service.assert_account(account_transfer_dto._target_card);
    User target_user = _auth_service.assert_user(target_account._user_id);

    if (account._card_number == target_account._card_number) {
        throw SameAccountException();
    }

    change_balance(account, - account_transfer_dto._sum);
    change_balance(target_account, account_transfer_dto._sum);

    _notification_service.notify(user, account, "Transfer performed from your card");
    _notification_service.notify(target_user, target_account, "Transfer performed to your card");
}

vector<Account> AccountService::get_debtors() const {
    time_t curr_time = time(nullptr);
    return _account_repository.get_list(AccountsDebtorAtTimeSpecification(CREDIT_SECONDS, curr_time));
}

void AccountService::punish_debtor(Account account) const {
    account._balance = floor(account._balance * CREDIT_COEFFICIENT);
    account._credit_start += CREDIT_SECONDS;
    _account_repository.update(account);
    User user = _auth_service.assert_user(account._user_id);
    _notification_service.notify(user, account, "You has been punished for your debt");
    if (account._credit_start + CREDIT_SECONDS < time(nullptr)) {
        punish_debtor(account);
    }
}

void AccountService::_assert_positive_sum(int sum) const {
    if (sum < 0) {
        throw NonPositiveNumberException();
    }
}

void AccountService::_assert_correct_balance(const Account &account) const {
    if (account._credit_limit == 0 && account._balance < 0) {
        throw SimpleCardBalanceException();
    }
    if (account._credit_limit != 0 && account._balance < -account._credit_limit) {
        throw CreditCardBalanceException();
    }
}

void AccountService::_update_credit_start(Account &account) const {
    if (account._credit_start != 0 && account._balance >= 0) {
        account._credit_start = 0;
        return;
    }
    if (account._credit_start == 0 && account._balance < 0) {
        account._credit_start = time(nullptr);
    }
}


void AccountService::change_balance(Account account, const int balance_change) const {
    account._balance += balance_change;

    _assert_correct_balance(account);

    _update_credit_start(account);
    _account_repository.update(account);
}
