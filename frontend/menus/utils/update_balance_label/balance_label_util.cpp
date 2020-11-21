//
// Created by alouh on 20.11.2020.
//
#include "balance_label_util.h"
void update_label(QLabel* label,const AccountBalanceDto& account_balance){
    QString balanceString;
    if (account_balance._credit_limit > 0)
        balanceString = QString("Your Balance: %1 $\n(Cred Limit: %2)").arg(1.*account_balance._balance/100).arg(1.*account_balance._credit_limit/100);
    else
        balanceString = QString("Your Balance: %1 $").arg(1.*account_balance._balance/100);
    label->setText(balanceString);
};

