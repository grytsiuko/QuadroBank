//
// Created by alouh on 20.11.2020.
//
#include "balance_label_util.h"
QString format_string(int input){
    int num = std::abs(input);
    string str = std::to_string(num);
    while (str.length() < 3)
        str = "0" + str;
    str.insert(str.length()-2, ".");
    if (input < 0)
        return ("-" + str).c_str();
    else
        return str.c_str();

}

void update_label(QLabel *label, const AccountBalanceDto &account_balance) {
    QString balanceString;
    if (account_balance._credit_limit > 0) {
        balanceString = QString("Your Balance: %1 $\n(Cred Limit: %2 $)").arg(format_string(account_balance._balance)).arg(
                format_string(account_balance._credit_limit));
    } else
        balanceString = QString("Your Balance: %1 $").arg(format_string(account_balance._balance));
    label->setText(balanceString);
};

