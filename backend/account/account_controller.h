#ifndef QUADROBANK_ACCOUNT_CONTROLLER_H
#define QUADROBANK_ACCOUNT_CONTROLLER_H

#include "dto/token_dto.h"
#include "dto/account_authorize_dto.h"
#include "account_service.h"
#include "../utils/singleton.h"
#include "../log/log_service.h"
#include "backend/utils/exceptions/exception.h"

class AccountController : public Singleton<AccountController> {

private:

    friend Singleton;

    const AccountService &_account_service;
    const LogService &_log_service;

    AccountController() :
            _account_service(AccountService::get_instance()),
            _log_service(LogService::get_instance()) {}

    void log(const string &text) const {
        _log_service.log("AccountController", text);
    }

public:

    Response<SessionDto> authorize(const AccountAuthorizeDto &account_authorize_dto) const;

    Response<AccountBalanceDto> check_balance(const TokenDto &token_dto) const;

    Response<void> top_up(const AccountUpdateDto &account_update_dto) const;

    Response<void> withdraw(const AccountUpdateDto &account_update_dto) const;

    Response<void> transfer(const AccountTransferDto &account_transfer_dto) const;
};

#endif
