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
        try{
            SessionTokenDto *result = _account_service.authorize(account_authorize_dto);
            return Response<SessionTokenDto>::success(result);
        } catch (const Exception &exception) {
            return Response<SessionTokenDto>::error(new string(exception.get_message()));
        }
    }

    Response<AccountBalanceDto> check_balance(const SessionTokenDto &sessionTokenDto) const {
        try {
            AccountBalanceDto *result = _account_service.check_balance(sessionTokenDto);
            return Response<AccountBalanceDto>::success(result);
        } catch (const Exception &exception) {
            return Response<AccountBalanceDto>::error(new string(exception.get_message()));
        }
    }

    Response<void> top_up(const AccountUpdateDto &account_update_dto) const {
        try {
            _account_service.top_up(account_update_dto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(new string(exception.get_message()));
        }
    }

    Response<void> withdraw(const AccountUpdateDto &account_update_dto) const {
        try {
            _account_service.withdraw(account_update_dto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(new string(exception.get_message()));
        }
    }

    Response<void> transfer(const AccountTransferDto &account_transfer_dto) const {
        try {
            _account_service.transfer(account_transfer_dto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(new string(exception.get_message()));
        }
    }
};

#endif
