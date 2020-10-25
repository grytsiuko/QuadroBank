#include <iostream>
#include <cassert>
#include "actions/account_actions.h"
#include "../backend/scheduler/scheduler.h"

using std::cout;

int main() {
    const Scheduler &scheduler = Scheduler::get_instance();

    // authorize
    AccountActions &accountActions = AccountActions::get_instance();
    Response<SessionDto> authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{"1111 1111 1111 1111", "1111"}
    );
    if (authorizeResponse.is_success()) {
        cout << "Authorized: " << authorizeResponse.get_response()->_name << "\n\n";
        TokenDto tokenDto = TokenDto{authorizeResponse.get_response()->_token};

        // check balance
        Response<AccountBalanceDto> balanceResponse = accountActions.check_balance(tokenDto);
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        // top up
        Response<void> topUpResponse = accountActions.top_up(
                AccountUpdateDto{authorizeResponse.get_response()->_token, 10});

        // check balance
        balanceResponse = accountActions.check_balance(tokenDto);
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        // withdraw
        Response<void> withdrawResponse = accountActions.withdraw(
                AccountUpdateDto{authorizeResponse.get_response()->_token, 1000});
        assert(withdrawResponse.is_error());
        // withdraw
        withdrawResponse = accountActions.withdraw(AccountUpdateDto{authorizeResponse.get_response()->_token, 130});
        assert(withdrawResponse.is_success());

        // check balance
        balanceResponse = accountActions.check_balance(tokenDto);
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(600));

        // check other balance
        Response<SessionDto> authorizeResponse2 = accountActions.authorize(
                AccountAuthorizeDto{"2222 2222 2222 2222", "2222"}
        );
        assert(authorizeResponse2.is_success());
        cout << "Authorized: " << authorizeResponse2.get_response()->_name << "\n\n";
        TokenDto tokenDto2 = TokenDto{authorizeResponse2.get_response()->_token};
        balanceResponse = accountActions.check_balance(tokenDto2);
        assert(balanceResponse.is_success());
        cout << "Other: " << balanceResponse.get_response()->_balance << "\n";

        // transfer
        Response<void> transferResponse = accountActions.transfer(
                AccountTransferDto({authorizeResponse2.get_response()->_token, "1111 1111 1111 1111", 1000})
        );
        assert(transferResponse.is_error());

        // transfer
        transferResponse = accountActions.transfer(
                AccountTransferDto({authorizeResponse2.get_response()->_token, "1111 1111 1111 1111", 50})
        );
        assert(transferResponse.is_success());

        // check balance
        balanceResponse = accountActions.check_balance(tokenDto);
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        // check other balance
        balanceResponse = accountActions.check_balance(tokenDto2);
        assert(balanceResponse.is_success());
        cout << "Other: " << balanceResponse.get_response()->_balance << "\n";
    } else {
        cout << "Unauthorized";
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(2100));
    return 0;
}