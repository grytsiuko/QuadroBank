#ifndef QUADROBANK_TOKEN_SERVICE_H
#define QUADROBANK_TOKEN_SERVICE_H

#include <string>
#include "../utils/singleton.h"
#include "../account/model/account.h"
#include "backend/utils/cypher/xor_cypher.h"

using std::string;

class TokenService : public Singleton<TokenService> {

    friend Singleton;

private:

    const CypherInterface& _cypher;

    TokenService() : _cypher(XORCypher::get_instance()){};

public:

    string generate_token(const Account &account) const;

    string get_card_number(const string &token) const;
};

#endif //QUADROBANK_TOKEN_SERVICE_H
