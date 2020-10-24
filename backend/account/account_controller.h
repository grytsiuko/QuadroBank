#ifndef QUADROBANK_ACCOUNT_CONTROLLER_H
#define QUADROBANK_ACCOUNT_CONTROLLER_H

#include "dto/session_token_dto.h"
#include "dto/account_authorize_dto.h"
#include "account_service.h"
#include "../utils/singleton.h"

class AccountController: public Singleton<AccountController> {

private:

    friend Singleton;

    const AccountService &_account_service;

    AccountController() : _account_service(AccountService::get_instance()) {}

public:

    Response<SessionTokenDto> authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        return _account_service.authorize(account_authorize_dto);
    }

    Response<AccountBalanceDto> check_balance(const SessionTokenDto &sessionTokenDto) const {
        return _account_service.check_balance(sessionTokenDto);
    }
};

#endif
