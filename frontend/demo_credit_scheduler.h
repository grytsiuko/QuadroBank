#ifndef QUADROBANK_DEMO_CREDIT_SCHEDULER_H
#define QUADROBANK_DEMO_CREDIT_SCHEDULER_H

#include "../backend/scheduler/scheduler.h"
#include "../backend/account/dto/account_authorize_dto.h"
#include "../backend/utils/response.h"
#include "../backend/account/dto/session_dto.h"
#include "actions/account_actions.h"

void demo_credit_scheduler() {
    const Scheduler &scheduler = Scheduler::get_instance();

    // authorize
    AccountActions &accountActions = AccountActions::get_instance();
    Response<SessionDto> authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{"3333 3333 3333 3333", "3333"}
    );
    assert(authorizeResponse.is_success());
    TokenDto tokenDto = TokenDto{authorizeResponse.get_response()->_token};

    // check balance
    Response<AccountBalanceDto> balanceResponse = accountActions.check_balance(tokenDto);
    assert(balanceResponse.is_success());
    cout << balanceResponse.get_response()->_balance << "\n";

    // withdraw
    Response<void> withdrawResponse = accountActions.withdraw(
            AccountUpdateDto{authorizeResponse.get_response()->_token, 130}
    );
    assert(withdrawResponse.is_success());

    // check balance
    balanceResponse = accountActions.check_balance(tokenDto);
    assert(balanceResponse.is_success());
    cout << balanceResponse.get_response()->_balance << "\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(5100));
}

#endif //QUADROBANK_DEMO_CREDIT_SCHEDULER_H
