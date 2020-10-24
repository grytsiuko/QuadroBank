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

class AccountService : public Singleton<AccountService> {

private:

    friend Singleton;

    const AccountRepositoryInterface<AccountRepositoryInMemory> &_account_repository;
    const TokenService &_token_service;

    AccountService() :
            _account_repository(AccountRepositoryInterface<AccountRepositoryInMemory>::get_instance()),
            _token_service(TokenService::get_instance()) {}

public:

    Response<SessionTokenDto> authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        Optional<Account> account = _account_repository.get_by_card_number(account_authorize_dto._card_number);
        if (account.is_empty()) {
            return Response<SessionTokenDto>::error(new string("No such card_number"));
        }

        if (account.get()->_pin != account_authorize_dto._pin) {
            return Response<SessionTokenDto>::error(new string("Illegal pin"));
        }

        auto *dto = new SessionTokenDto{
                _token_service.generate_token(*account.get())
        };
        return Response<SessionTokenDto>::success(dto);
    }

    Response<AccountBalanceDto> check_balance(const SessionTokenDto &sessionTokenDto) const {
        string card_number = _token_service.get_card_number(sessionTokenDto._token);
        Optional<Account> account = _account_repository.get_by_card_number(card_number);

        if (account.is_empty()) {
            return Response<AccountBalanceDto>::error(new string("Illegal token"));
        }

        return Response<AccountBalanceDto>::success(new AccountBalanceDto(*account.get()));
    }
};

#endif
