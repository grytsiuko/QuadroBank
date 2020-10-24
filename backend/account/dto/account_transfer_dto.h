#ifndef QUADROBANK_ACCOUNT_TRANSFER_DTO_H
#define QUADROBANK_ACCOUNT_TRANSFER_DTO_H

#include <string>

using std::string;

struct AccountTransferDto {
    string _token;
    string _target_card;
    int _sum;
};

#endif //QUADROBANK_ACCOUNT_TRANSFER_DTO_H
