#ifndef QUADROBANK_DEMO_CREDIT_SCHEDULER_H
#define QUADROBANK_DEMO_CREDIT_SCHEDULER_H

#include "../backend/scheduler/scheduler.h"
#include "../backend/account/dto/account_authorize_dto.h"
#include "../backend/utils/response.h"
#include "../backend/account/dto/session_dto.h"
#include "actions/account_actions.h"

void demo_credit_check_balance(const TokenDto &tokenDto) {
    Response<AccountBalanceDto> balanceResponse = AccountActions::get_instance().check_balance(tokenDto);
    assert(balanceResponse.is_success());
    cout << balanceResponse.get_response()->_balance << "\n";
}

void demo_credit_scheduler() {
    const Scheduler &scheduler = Scheduler::get_instance();

    // authorize
    AccountActions &accountActions = AccountActions::get_instance();
    Response<SessionDto> authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{"3333 3333 3333 3333", "3333"}
    );
    assert(authorizeResponse.is_success());
    TokenDto tokenDto = TokenDto{authorizeResponse.get_response()->_token};

    demo_credit_check_balance(tokenDto);

    // withdraw
    Response<void> withdrawResponse = accountActions.withdraw(
            AccountUpdateDto{authorizeResponse.get_response()->_token, 100}
    );
    assert(withdrawResponse.is_success());

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        demo_credit_check_balance(tokenDto);
    }

    // top up
    Response<void> topUpResponse = accountActions.top_up(
            AccountUpdateDto{authorizeResponse.get_response()->_token, 300}
    );
    assert(withdrawResponse.is_success());

    demo_credit_check_balance(tokenDto);
}

#endif //QUADROBANK_DEMO_CREDIT_SCHEDULER_H
