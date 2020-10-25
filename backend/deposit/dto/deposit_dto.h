#ifndef QUADROBANK_DEPOSIT_DTO_H
#define QUADROBANK_DEPOSIT_DTO_H

#include <ctime>

struct DepositDto {
    int _id;
    int _period_sec;
    time_t _start_date;
    time_t _end_date;
    double _percentage;
    int _sum;
};

#endif //QUADROBANK_DEPOSIT_DTO_H
