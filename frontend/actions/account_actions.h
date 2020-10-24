#ifndef QUADROBANK_ACCOUNT_ACTIONS_H
#define QUADROBANK_ACCOUNT_ACTIONS_H

#include "../../backend/account/dto/session_token_dto.h"
#include "../../backend/account/dto/account_authorize_dto.h"
#include "../../backend/account/account_controller.h"
#include "../../backend/utils/singleton.h"

class AccountActions: public Singleton<AccountActions> {

private:

    friend Singleton;

    const AccountController &_account_controller;

    AccountActions() : _account_controller(AccountController::get_instance()) {}

public:

    Response<SessionTokenDto> authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        return _account_controller.authorize(account_authorize_dto);
    }

    Response<AccountBalanceDto> check_balance(const SessionTokenDto &sessionTokenDto) const {
        return _account_controller.check_balance(sessionTokenDto);
    }

    Response<void> top_up(const AccountUpdateDto &accountUpdateDto) const {
        return _account_controller.top_up(accountUpdateDto);
    }
};

#endif
