//
// Created by alouh on 20.11.2020.
//

#ifndef QUADROBANK_BALANCE_LABEL_UTIL_H
#define QUADROBANK_BALANCE_LABEL_UTIL_H
#include <QLabel>
#include "../backend/account/model/account.h"
#include "../backend/account/dto/account_balance_dto.h"
void update_label(QLabel* label, const AccountBalanceDto&, const std::string&);
#endif //QUADROBANK_BALANCE_LABEL_UTIL_H
