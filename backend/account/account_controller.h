#ifndef QUADROBANK_ACCOUNT_CONTROLLER_H
#define QUADROBANK_ACCOUNT_CONTROLLER_H

#include "dto/session_token_dto.h"
#include "dto/account_authorize_dto.h"

class AccountController {

private:

    AccountController() = default;

    ~AccountController() = default;

public:

    AccountController(const AccountController &) = delete;

    AccountController &operator=(const AccountController &) = delete;

    static AccountController &get_instance() {
        static AccountController instance;
        return instance;
    }

    SessionTokenDto authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        return SessionTokenDto{account_authorize_dto._card_number + "#" + account_authorize_dto._pin};
    }
};

#endif
