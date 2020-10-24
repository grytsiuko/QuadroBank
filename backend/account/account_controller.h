#ifndef QUADROBANK_ACCOUNT_CONTROLLER_H
#define QUADROBANK_ACCOUNT_CONTROLLER_H

#include "dto/session_token_dto.h"
#include "dto/account_authorize_dto.h"
#include "account_service.h"

class AccountController {

private:

    const AccountService &_account_service;

    AccountController() : _account_service(AccountService::get_instance()) {}

    ~AccountController() = default;

public:

    AccountController(const AccountController &) = delete;

    AccountController &operator=(const AccountController &) = delete;

    static AccountController &get_instance() {
        static AccountController instance;
        return instance;
    }

    Response<SessionTokenDto> authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        return _account_service.authorize(account_authorize_dto);
    }
};

#endif
