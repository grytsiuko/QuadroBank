#include <iostream>
#include <cassert>
#include "actions/account_actions.h"

using std::cout;

int main() {
    AccountActions &accountActions = AccountActions::get_instance();
    Response<SessionTokenDto> authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{"1111 1111 1111 1111", "1111"}
    );
    if (authorizeResponse.is_success()) {
        Response<AccountBalanceDto> balanceResponse = accountActions.check_balance(*authorizeResponse.get_response());
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance;
    } else {
        cout << "Unauthorized";
    }
    return 0;
}