#include <iostream>
#include <cassert>
#include "actions/account_actions.h"

using std::cout;

int main() {
    // authorize
    AccountActions &accountActions = AccountActions::get_instance();
    Response<SessionDto> authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{"1111 1111 1111 1111", "1111"}
    );
    if (authorizeResponse.is_success()) {
        cout << "Authorized: " << authorizeResponse.get_response()->_name << "\n\n";
        TokenDto tokenDto = TokenDto{authorizeResponse.get_response()->_token};
        cout << "check balance\n";
        Response<AccountBalanceDto> balanceResponse = accountActions.check_balance(tokenDto);
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        cout << "top up 10\n";
        Response<void> topUpResponse = accountActions.top_up(
                AccountUpdateDto{authorizeResponse.get_response()->_token, 10});

        cout << "check balance\n";
        balanceResponse = accountActions.check_balance(tokenDto);
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
        balanceResponse = accountActions.check_balance(tokenDto);
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        cout << "\n\ncheck other balance\n";
        Response<SessionDto> authorizeResponse2 = accountActions.authorize(
                AccountAuthorizeDto{"2222 2222 2222 2222", "2222"}
        );
        assert(authorizeResponse2.is_success());
        cout << "Authorized: " << authorizeResponse2.get_response()->_name << "\n\n";
        TokenDto tokenDto2 = TokenDto{authorizeResponse2.get_response()->_token};
        balanceResponse = accountActions.check_balance(tokenDto2);
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
        balanceResponse = accountActions.check_balance(tokenDto);
        assert(balanceResponse.is_success());
        cout << balanceResponse.get_response()->_balance << "\n";

        cout << "check other balance\n";
        balanceResponse = accountActions.check_balance(tokenDto2);
        assert(balanceResponse.is_success());
        cout << "Other: " << balanceResponse.get_response()->_balance << "\n";
    } else {
        cout << "Unauthorized";
    }
    return 0;
}