#include <iostream>
#include <cassert>
#include "actions/account_actions.h"
#include "../backend/scheduler/scheduler.h"

using std::cout;

int main() {
    Scheduler &scheduler = Scheduler::get_instance();
    scheduler.start();

    // authorize
    AccountActions &accountActions = AccountActions::get_instance();
    Response<SessionTokenDto> authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{"1111 1111 1111 1111", "1111"}
    );
    if (authorizeResponse.is_success()) {
        cout << "check balance\n";
        Response<AccountBalanceDto> balanceResponse = accountActions.check_balance(*authorizeResponse.get_response());
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        cout << "top up 10\n";
        Response<void> topUpResponse = accountActions.top_up(
                AccountUpdateDto{authorizeResponse.get_response()->_token, 10});

        cout << "check balance\n";
        balanceResponse = accountActions.check_balance(*authorizeResponse.get_response());
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        cout << "withdraw 1000 - error\n";
        Response<void> withdrawResponse = accountActions.withdraw(
                AccountUpdateDto{authorizeResponse.get_response()->_token, 1000});
        assert(withdrawResponse.is_error());
        cout << "withdraw 130\n";
        withdrawResponse = accountActions.withdraw(AccountUpdateDto{authorizeResponse.get_response()->_token, 130});
        assert(withdrawResponse.is_success());

        cout << "check balance\n";
        balanceResponse = accountActions.check_balance(*authorizeResponse.get_response());
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        cout << "\n\ncheck other balance\n";
        Response<SessionTokenDto> authorizeResponse2 = accountActions.authorize(
                AccountAuthorizeDto{"2222 2222 2222 2222", "2222"}
        );
        assert(authorizeResponse2.is_success());
        balanceResponse = accountActions.check_balance(*authorizeResponse2.get_response());
        assert(balanceResponse.is_success());
        cout << "Other: " << balanceResponse.get_response()->_balance << "\n";

        cout << "transfer from other 1000 - error\n";
        Response<void> transferResponse = accountActions.transfer(
                AccountTransferDto({authorizeResponse2.get_response()->_token, "1111 1111 1111 1111", 1000})
        );
        assert(transferResponse.is_error());

        cout << "transfer from other 50\n";
        transferResponse = accountActions.transfer(
                AccountTransferDto({authorizeResponse2.get_response()->_token, "1111 1111 1111 1111", 50})
        );
        assert(transferResponse.is_success());

        cout << "check balance\n";
        balanceResponse = accountActions.check_balance(*authorizeResponse.get_response());
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        cout << "check other balance\n";
        balanceResponse = accountActions.check_balance(*authorizeResponse2.get_response());
        assert(balanceResponse.is_success());
        cout << "Other: " << balanceResponse.get_response()->_balance << "\n";
    } else {
        cout << "Unauthorized";
    }

    scheduler.end();
    return 0;
}