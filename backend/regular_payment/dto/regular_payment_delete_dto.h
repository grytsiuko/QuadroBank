#ifndef QUADROBANK_REGULAR_PAYMENT_DELETE_DTO_H
#define QUADROBANK_REGULAR_PAYMENT_DELETE_DTO_H

#include <string>

using std::string;

struct RegularPaymentDeleteDto {
    string _token;
    int _payment_id;
};

#endif //QUADROBANK_REGULAR_PAYMENT_DELETE_DTO_H
