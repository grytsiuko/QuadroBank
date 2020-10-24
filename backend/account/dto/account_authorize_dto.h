#ifndef QUADROBANK_ACCOUNT_AUTHORIZE_DTO_H
#define QUADROBANK_ACCOUNT_AUTHORIZE_DTO_H

#include <string>

using std::string;

struct AccountAuthorizeDto {
    string _card_number;
    string _pin;
};

#endif
