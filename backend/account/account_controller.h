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

    Response<void> top_up(const AccountUpdateDto &account_update_dto) const {
        return _account_service.top_up(account_update_dto);
    }

    Response<void> withdraw(const AccountUpdateDto &account_update_dto) const {
        return _account_service.withdraw(account_update_dto);
    }

    Response<void> transfer(const AccountTransferDto &account_transfer_dto) const {
        return _account_service.transfer(account_transfer_dto);
    }
};

#endif
