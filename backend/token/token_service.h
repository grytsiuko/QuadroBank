#ifndef QUADROBANK_TOKEN_SERVICE_H
#define QUADROBANK_TOKEN_SERVICE_H

#include <string>
#include "../utils/singleton.h"
#include "../account/model/account.h"

using std::string;

class TokenService: public Singleton<TokenService> {

private:

    friend Singleton;

    TokenService() = default;

public:

    string generate_token(const Account &account) const {
        return account._card_number;
    }

    string get_card_number(const string &token) const {
        return token;
    }
};

#endif //QUADROBANK_TOKEN_SERVICE_H
