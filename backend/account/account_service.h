#ifndef QUADROBANK_ACCOUNT_SERVICE_H
#define QUADROBANK_ACCOUNT_SERVICE_H

#include "dto/account_authorize_dto.h"
#include "dto/token_dto.h"
#include "account_repository_interface.h"
#include "account_repository_in_memory.h"
#include "../utils/response.h"
#include "../utils/singleton.h"
#include "dto/account_balance_dto.h"
#include "../token/token_service.h"
#include "dto/account_update_dto.h"
#include "dto/account_transfer_dto.h"
#include "../utils/exception.h"
#include "../user/user_repository_interface.h"
#include "../user/user_repository_in_memory.h"
#include "dto/session_dto.h"

class AccountService : public Singleton<AccountService> {

private:

    const static int CREDIT_SECONDS = 1;

    friend Singleton;

    const AccountRepositoryInterface<AccountRepositoryInMemory> &_account_repository;
    const UserRepositoryInterface<UserRepositoryInMemory> &_user_repository;
    const TokenService &_token_service;

    AccountService() :
            _account_repository(AccountRepositoryInterface<AccountRepositoryInMemory>::get_instance()),
            _user_repository(UserRepositoryInterface<UserRepositoryInMemory>::get_instance()),
            _token_service(TokenService::get_instance()) {}

public:

    SessionDto *authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        Account account = _assert_account_by_card_number(account_authorize_dto._card_number);
        User user = _assert_user_by_id(account._user_id);

        if (account._pin != account_authorize_dto._pin) {
            throw Exception("Illegal pin");
        }

        return new SessionDto{_token_service.generate_token(account), user._name};
    }

    AccountBalanceDto *check_balance(const TokenDto &token_dto) const {
        Account account = _assert_account_by_token(token_dto._token);

        return new AccountBalanceDto(account);
    }

    void top_up(const AccountUpdateDto &account_update_dto) const {
        _assert_positive_sum(account_update_dto._sum);

        Account account = _assert_account_by_token(account_update_dto._token);
        account._balance += account_update_dto._sum;

        _account_repository.update(account);
    }

    void withdraw(const AccountUpdateDto &account_update_dto) const {
        _assert_positive_sum(account_update_dto._sum);

        Account account = _assert_account_by_token(account_update_dto._token);
        account._balance -= account_update_dto._sum;

        _assert_correct_balance(account);
        _update_credit_start(account, account_update_dto._sum);

        _account_repository.update(account);
    }

    void transfer(const AccountTransferDto &account_transfer_dto) const {
        _assert_positive_sum(account_transfer_dto._sum);

        Account account = _assert_account_by_token(account_transfer_dto._token);
        Account target_account = _assert_account_by_card_number(account_transfer_dto._target_card);

        account._balance -= account_transfer_dto._sum;
        target_account._balance += account_transfer_dto._sum;

        _assert_correct_balance(account);
        _update_credit_start(account, account_transfer_dto._sum);

        _account_repository.update(account);
        _account_repository.update(target_account);
    }

    vector<Account> get_debtors() const {
        bool (*debtors_filter)(const Account &) = [](auto &a) {
            return a._credit_start != 0 && a._credit_start + CREDIT_SECONDS < time(nullptr);
        };
        return _account_repository.get_list(AccountSpecification(debtors_filter));
    }

private:

    void _assert_positive_sum(int sum) const {
        if (sum < 0) {
            throw Exception("Sum should be positive");
        }
    }

    void _assert_correct_balance(const Account &account) const {
        if (!account._is_credit && account._balance < 0) {
            throw Exception("You have simple card, you cannot have negative balance");
        }
        if (account._is_credit && account._balance < -account._credit_limit) {
            throw Exception("You cannot exceed your credit limit");
        }
    }

    void _update_credit_start(Account &account, int sum) const {
        if (account._credit_start != 0 && account._balance >= 0) {
            account._credit_start = 0;
            return;
        }
        if (account._credit_start == 0 && account._balance < 0) {
            account._credit_start = time(nullptr);
        }
    }

    Account _assert_account_by_token(const string &token) const {
        string card_number = _token_service.get_card_number(token);
        Optional<Account> account = _account_repository.get_by_card_number(card_number);

        if (account.is_empty()) {
            throw Exception("Illegal token");
        }
        return Account(*account.get());
    }

    Account _assert_account_by_card_number(const string &card_number) const {
        Optional<Account> account = _account_repository.get_by_card_number(card_number);

        if (account.is_empty()) {
            throw Exception("No such card number");
        }
        return Account(*account.get());
    }

    User _assert_user_by_id(const int id) const {
        Optional<User> user = _user_repository.get_by_id(id);

        if (user.is_empty()) {
            throw Exception("Internal error, no such user");
        }
        return User(*user.get());
    }
};

#endif
