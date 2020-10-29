#ifndef QUADROBANK_DEPOSIT_CREATE_DTO_H
#define QUADROBANK_DEPOSIT_CREATE_DTO_H

#include <string>

using std::string;

struct DepositCreateDto {
    string _token;
    double _percentage;
    int _period_sec;
    int _sum;
};

#endif //QUADROBANK_DEPOSIT_CREATE_DTO_H
