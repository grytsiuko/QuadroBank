#ifndef QUADROBANK_ACCOUNT_CONTROLLER_H
#define QUADROBANK_ACCOUNT_CONTROLLER_H

#include "dto/token_dto.h"
#include "dto/account_authorize_dto.h"
#include "account_service.h"
#include "../utils/singleton.h"
#include "../log/log_service.h"
#include "../utils/exception.h"

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

    Response<SessionDto> authorize(const AccountAuthorizeDto &account_authorize_dto) const {
        log("authorize");
        try {
            SessionDto result = _account_service.authorize(account_authorize_dto);
            return Response<SessionDto>::success(result);
        } catch (const Exception &exception) {
            return Response<SessionDto>::error(exception.get_message());
        }
    }

    Response<AccountBalanceDto> check_balance(const TokenDto &token_dto) const {
        log("check balance");
        try {
            AccountBalanceDto result = _account_service.check_balance(token_dto);
            return Response<AccountBalanceDto>::success(result);
        } catch (const Exception &exception) {
            return Response<AccountBalanceDto>::error(exception.get_message());
        }
    }

    Response<void> top_up(const AccountUpdateDto &account_update_dto) const {
        log("top up");
        try {
            _account_service.top_up(account_update_dto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(exception.get_message());
        }
    }

    Response<void> withdraw(const AccountUpdateDto &account_update_dto) const {
        log("withdraw");
        try {
            _account_service.withdraw(account_update_dto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(exception.get_message());
        }
    }

    Response<void> transfer(const AccountTransferDto &account_transfer_dto) const {
        log("transfer");
        try {
            _account_service.transfer(account_transfer_dto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(exception.get_message());
        }
    }
};

#endif
