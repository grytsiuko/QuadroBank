//
// Created by alouh on 20.11.2020.
//
#include <iostream>
#include "balance_label_util.h"
void update_label(QLabel* label,const AccountBalanceDto& account_balance, const std::string& name){
    std::cout << name << std::endl;
    QString balanceString;
    if (account_balance._credit_limit > 0)
        balanceString = QString("%1, Your Balance: %2 $\n(Cred Limit: %3)").arg(QString::fromStdString(name)).arg(1.*account_balance._balance/100).arg(1.*account_balance._credit_limit/100);
    else
        balanceString = QString("%1, Your Balance: %2 $").arg(QString::fromStdString(name)).arg(1.*account_balance._balance/100);
    label->setText(balanceString);
};
