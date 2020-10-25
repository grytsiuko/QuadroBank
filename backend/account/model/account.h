#ifndef QUADROBANK_ACCOUNT_H
#define QUADROBANK_ACCOUNT_H

#include <string>

using std::string;

struct Account {
    string _card_number;
    int _user_id;
    string _pin;
    bool _is_credit;
    int _balance;
    int _credit_limit;
};

#endif //QUADROBANK_ACCOUNT_H
