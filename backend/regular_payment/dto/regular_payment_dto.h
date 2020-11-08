#ifndef QUADROBANK_REGULAR_PAYMENT_DTO_H
#define QUADROBANK_REGULAR_PAYMENT_DTO_H

#include <string>

using std::string;

struct RegularPaymentDto {
    int _id;
    int _period_sec;
    string _target_card;
    int _sum;
    time_t _next_time;
};

#endif //QUADROBANK_REGULAR_PAYMENT_DTO_H
