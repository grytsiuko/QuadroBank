#ifndef QUADROBANK_DEMO_DEPOSIT_SCHEDULER_H
#define QUADROBANK_DEMO_DEPOSIT_SCHEDULER_H

#include <cassert>
#include <frontend/actions/deposit_actions.h>
#include "../backend/scheduler/scheduler.h"
#include "../backend/account/dto/account_authorize_dto.h"
#include "../backend/utils/response.h"
#include "../backend/account/dto/session_dto.h"
#include "actions/account_actions.h"

void demo_deposit_check_balance(const TokenDto &tokenDto) {
    Response<AccountBalanceDto> balanceResponse = AccountActions::get_instance().check_balance(tokenDto);
    assert(balanceResponse.is_success());
    cout << balanceResponse.get_response()->_balance << "\n";
}

void demo_deposit_show_deposits(const TokenDto &tokenDto) {
    Response<vector<DepositDto>> depositResponse = DepositActions::get_instance().get_all_by_user(tokenDto);
    assert(depositResponse.is_success());
    cout << depositResponse.get_response()->size() << " deposits\n";
    for (const DepositDto &depositDto:*depositResponse.get_response()) {
        cout << depositDto._sum << " until " << ctime(&depositDto._end_date) << std::endl;
    }
}

void demo_deposit_scheduler() {
    const Scheduler &scheduler = Scheduler::get_instance();

    // authorize
    AccountActions &accountActions = AccountActions::get_instance();
    DepositActions &depositActions = DepositActions::get_instance();
    Response<SessionDto> authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{"2222 2222 2222 2222", "2222"}
    );
    assert(authorizeResponse.is_success());
    TokenDto tokenDto = TokenDto{authorizeResponse.get_response()->_token};

    demo_deposit_check_balance(tokenDto);
    demo_deposit_show_deposits(tokenDto);

    // add deposit
    Response<void> depositResponse = depositActions.create(
            DepositCreateDto{authorizeResponse.get_response()->_token, 10000, 20000}
    );
    assert(depositResponse.is_success());

    demo_deposit_check_balance(tokenDto);
    demo_deposit_show_deposits(tokenDto);

    std::this_thread::sleep_for(std::chrono::milliseconds(12000));


    demo_deposit_check_balance(tokenDto);
    demo_deposit_show_deposits(tokenDto);
}

#endif //QUADROBANK_DEMO_DEPOSIT_SCHEDULER_H
