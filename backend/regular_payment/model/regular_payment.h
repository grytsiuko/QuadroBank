#ifndef QUADROBANK_REGULAR_PAYMENT_H
#define QUADROBANK_REGULAR_PAYMENT_H

#include <string>
using std::string;

struct RegularPayment{
    int _id;
    string _account_id;
    int _period_sec;
    string _target_account;
    time_t _last_paid;
    int _sum;
};

#endif //QUADROBANK_REGULAR_PAYMENT_H
