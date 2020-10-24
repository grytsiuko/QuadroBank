#include <iostream>
#include <cassert>
#include "actions/account_actions.h"

using std::cout;

int main() {
    // authorize
    AccountActions &accountActions = AccountActions::get_instance();
    Response<SessionTokenDto> authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{"1111 1111 1111 1111", "1111"}
    );
    if (authorizeResponse.is_success()) {
        // check balance
        Response<AccountBalanceDto> balanceResponse = accountActions.check_balance(*authorizeResponse.get_response());
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        // top up
        Response<void> topUpResponse = accountActions.top_up(AccountUpdateDto{authorizeResponse.get_response()->_token, 10});

        // check balance
        balanceResponse = accountActions.check_balance(*authorizeResponse.get_response());
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";
    } else {
        cout << "Unauthorized";
    }
    return 0;
}