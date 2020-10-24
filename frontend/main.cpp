#include <iostream>
#include "communication/frontend_communication.h"
#include "actions/account_actions.h"

int main() {
    SessionTokenDto sessionTokenDto =
            AccountActions::get_instance().authorize(AccountAuthorizeDto{"123", "111"});
    cout << sessionTokenDto._token;
    return 0;
}