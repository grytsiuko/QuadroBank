#ifndef QUADROBANK_ACCOUNT_ACTIONS_H
#define QUADROBANK_ACCOUNT_ACTIONS_H

#include "../../backend/account/dto/session_token_dto.h"
#include "../../backend/account/dto/account_authorize_dto.h"
#include "../../backend/account/account_controller.h"

class AccountActions {

private:

    const AccountController &_account_controller;

    AccountActions() : _account_controller(AccountController::get_instance()) {}

    ~AccountActions() = default;

public:

    AccountActions(const AccountActions &) = delete;

    AccountActions &operator=(const AccountActions &) = delete;

    static AccountActions &get_instance() {
        static AccountActions instance;
        return instance;
    }

    Response<SessionTokenDto> authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        return _account_controller.authorize(account_authorize_dto);
    }
};

#endif
