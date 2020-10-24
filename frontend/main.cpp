#include <iostream>
#include "actions/account_actions.h"

int main() {
    Response<SessionTokenDto> authorizeResponse =
            AccountActions::get_instance().authorize(AccountAuthorizeDto{"123", "111"});
    if (authorizeResponse.is_present()) {
        std::cout << authorizeResponse.get_value()->_token;
    } else {
        std::cout << "Unauthorized";
    }
    return 0;
}