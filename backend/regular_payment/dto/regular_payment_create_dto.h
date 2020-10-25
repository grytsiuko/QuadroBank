#ifndef QUADROBANK_REGULAR_PAYMENT_CREATE_DTO_H
#define QUADROBANK_REGULAR_PAYMENT_CREATE_DTO_H

#include <string>

using std::string;

struct RegularPaymentCreateDto {
    string _token;
    time_t _next_time;
    int _period_sec;
    string _target_card;
    int _sum;
};

#endif //QUADROBANK_REGULAR_PAYMENT_CREATE_DTO_H
