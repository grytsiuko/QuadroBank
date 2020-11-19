
#include <backend/utils/exceptions/no_such_card_exception.h>
#include <backend/utils/exceptions/no_such_user_exception.h>
#include "auth_service.h"

Account AuthService::assert_account(const string &card_number) const {
    Optional<Account> account = _account_repository.get_by_card_number(card_number);

    if (account.is_empty()) {
        throw NoSuchCardException();
    }
    return account.get();
}

User AuthService::assert_user(int user_id) const {
    Optional<User> user = _user_repository.get_by_id(user_id);

    if (user.is_empty()) {
        throw NoSuchUserException();
    }
    return user.get();
}
