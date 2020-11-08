#include "account_controller.h"

Response<SessionDto> AccountController::authorize(const AccountAuthorizeDto &account_authorize_dto) const {
    log("authorize");
    try {
        SessionDto result = _account_service.authorize(account_authorize_dto);
        return Response<SessionDto>::success(result);
    } catch (const Exception &exception) {
        return Response<SessionDto>::error(exception.get_message());
    }
}

Response<AccountBalanceDto> AccountController::check_balance(const TokenDto &token_dto) const {
    log("check balance");
    try {
        AccountBalanceDto result = _account_service.check_balance(token_dto);
        return Response<AccountBalanceDto>::success(result);
    } catch (const Exception &exception) {
        return Response<AccountBalanceDto>::error(exception.get_message());
    }
}

Response<void> AccountController::top_up(const AccountUpdateDto &account_update_dto) const {
    log("top up");
    try {
        _account_service.top_up(account_update_dto);
        return Response<void>::success();
    } catch (const Exception &exception) {
        return Response<void>::error(exception.get_message());
    }
}

Response<void> AccountController::withdraw(const AccountUpdateDto &account_update_dto) const {
    log("withdraw");
    try {
        _account_service.withdraw(account_update_dto);
        return Response<void>::success();
    } catch (const Exception &exception) {
        return Response<void>::error(exception.get_message());
    }
}

Response<void> AccountController::transfer(const AccountTransferDto &account_transfer_dto) const {
    log("transfer");
    try {
        _account_service.transfer(account_transfer_dto);
        return Response<void>::success();
    } catch (const Exception &exception) {
        return Response<void>::error(exception.get_message());
    }
}


