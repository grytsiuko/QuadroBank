#include <iostream>
#include "actions/account_actions.h"

int main() {
    Response<SessionTokenDto> authorizeResponse =
            AccountActions::get_instance().authorize(AccountAuthorizeDto{
                "1111 1111 1111 1111", "1111"
            });
    if (authorizeResponse.is_success()) {
        std::cout << authorizeResponse.get_response()->_token;
    } else {
        std::cout << "Unauthorized";
    }
    return 0;
}