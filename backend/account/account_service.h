#ifndef QUADROBANK_ACCOUNT_SERVICE_H
#define QUADROBANK_ACCOUNT_SERVICE_H

#include "dto/account_authorize_dto.h"
#include "dto/session_token_dto.h"
#include "account_repository_interface.h"
#include "account_repository_in_memory.h"
#include "../utils/response.h"
#include "../utils/singleton.h"
#include "dto/account_balance_dto.h"
#include "../token/token_service.h"
#include "dto/account_update_dto.h"
#include "dto/account_transfer_dto.h"
#include "../utils/exception.h"

class AccountService : public Singleton<AccountService> {

private:

    friend Singleton;

    const AccountRepositoryInterface<AccountRepositoryInMemory> &_account_repository;
    const TokenService &_token_service;

    AccountService() :
            _account_repository(AccountRepositoryInterface<AccountRepositoryInMemory>::get_instance()),
            _token_service(TokenService::get_instance()) {}

public:

    SessionTokenDto *authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        Optional<Account> account = _account_repository.get_by_card_number(account_authorize_dto._card_number);
        if (account.is_empty()) {
            throw Exception("No such card number");
        }

        if (account.get()->_pin != account_authorize_dto._pin) {
            throw Exception("Illegal pin");
        }

        return new SessionTokenDto{
                _token_service.generate_token(*account.get())
        };
    }

    AccountBalanceDto *check_balance(const SessionTokenDto &session_token_dto) const {
        string card_number = _token_service.get_card_number(session_token_dto._token);
        Optional<Account> account = _account_repository.get_by_card_number(card_number);

        if (account.is_empty()) {
            throw Exception("Illegal token");
        }

        return new AccountBalanceDto(*account.get());
    }

    void top_up(const AccountUpdateDto &account_update_dto) const {
        if (account_update_dto._sum <= 0) {
            throw Exception("Sum should be positive");
        }

        string card_number = _token_service.get_card_number(account_update_dto._token);
        Optional<Account> account = _account_repository.get_by_card_number(card_number);

        if (account.is_empty()) {
            throw Exception("Illegal token");
        }

        Account account_copy = Account(*account.get());
        account_copy._balance += account_update_dto._sum;
        _account_repository.update(account_copy);
    }

    void withdraw(const AccountUpdateDto &account_update_dto) const {
        if (account_update_dto._sum <= 0) {
            throw Exception("Sum should be positive");
        }

        string card_number = _token_service.get_card_number(account_update_dto._token);
        Optional<Account> account = _account_repository.get_by_card_number(card_number);

        if (account.is_empty()) {
            throw Exception("Illegal token");
        }

        Account account_copy = Account(*account.get());
        account_copy._balance -= account_update_dto._sum;

        if (!account_copy._is_credit && account_copy._balance < 0) {
            throw Exception("You have simple card, you cannot have negative balance");
        }

        if (account_copy._is_credit && account_copy._balance < -account_copy._credit_limit) {
            throw Exception("You cannot exceed your credit limit");
        }

        _account_repository.update(account_copy);
    }

    void transfer(const AccountTransferDto &account_transfer_dto) const {
        if (account_transfer_dto._sum <= 0) {
            throw Exception("Sum should be positive");
        }

        string card_number = _token_service.get_card_number(account_transfer_dto._token);
        Optional<Account> account = _account_repository.get_by_card_number(card_number);

        if (account.is_empty()) {
            throw Exception("Illegal token");
        }

        Optional<Account> target_account = _account_repository.get_by_card_number(account_transfer_dto._target_card);

        if (target_account.is_empty()) {
            throw Exception("No such target card");
        }

        Account account_copy = Account(*account.get());
        Account target_account_copy = Account(*target_account.get());
        account_copy._balance -= account_transfer_dto._sum;
        target_account_copy._balance += account_transfer_dto._sum;

        if (!account_copy._is_credit && account_copy._balance < 0) {
            throw Exception("You have simple card, you cannot have negative balance");
        }

        if (account_copy._is_credit && account_copy._balance < -account_copy._credit_limit) {
            throw Exception("You cannot exceed your credit limit");
        }

        _account_repository.update(account_copy);
        _account_repository.update(target_account_copy);
    }
};

#endif
