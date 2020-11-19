#include "token_service.h"

string TokenService::generate_token(const Account &account) const {
    return account._card_number;
}

string TokenService::get_card_number(const string &token) const {
    return token;
}
