#ifndef QUADROBANK_REGULAR_PAYMENT_UPDATE_DTO_H
#define QUADROBANK_REGULAR_PAYMENT_UPDATE_DTO_H

#include <string>

using std::string;

struct RegularPaymentUpdateDto {
    string _token;
    int _payment_id;
    int _period_sec;
    int _next_time;
    string _target_card;
    int _sum;
};

#endif //QUADROBANK_REGULAR_PAYMENT_UPDATE_DTO_H
