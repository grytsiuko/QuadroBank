#ifndef QUADROBANK_ACCOUNT_ACTIONS_H
#define QUADROBANK_ACCOUNT_ACTIONS_H

#include "../../backend/account/dto/token_dto.h"
#include "../../backend/account/dto/account_authorize_dto.h"
#include "../../backend/account/account_controller.h"
#include "../../backend/utils/singleton.h"

class AccountActions: public Singleton<AccountActions> {

private:

    friend Singleton;

    const AccountController &_account_controller;

    AccountActions() : _account_controller(AccountController::get_instance()) {}

public:

    Response<SessionDto> authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        return _account_controller.authorize(account_authorize_dto);
    }

    Response<AccountBalanceDto> check_balance(const TokenDto &token_dto) const {
        return _account_controller.check_balance(token_dto);
    }

    Response<void> top_up(const AccountUpdateDto &accountUpdateDto) const {
        return _account_controller.top_up(accountUpdateDto);
    }

    Response<void> withdraw(const AccountUpdateDto &account_update_dto) const {
        return _account_controller.withdraw(account_update_dto);
    }

    Response<void> transfer(const AccountTransferDto &account_transfer_dto) const {
        return _account_controller.transfer(account_transfer_dto);
    }
};

#endif
