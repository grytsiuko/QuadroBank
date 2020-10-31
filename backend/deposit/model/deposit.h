#ifndef QUADROBANK_DEPOSIT_H
#define QUADROBANK_DEPOSIT_H

#include <string>

using std::string;

struct Deposit {
    int _id;
    string _account_card_number;
    double _percentage;
    int _period_sec;
    time_t _start_date;
    time_t _end_date;
    int _sum;
};

#endif //QUADROBANK_DEPOSIT_H
