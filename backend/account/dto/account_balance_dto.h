#ifndef QUADROBANK_ACCOUNT_BALANCE_DTO_H
#define QUADROBANK_ACCOUNT_BALANCE_DTO_H

struct AccountBalanceDto {
    int _balance;
    int _credit_limit;

    explicit AccountBalanceDto(const Account &account) :
            _balance(account._balance),
            _credit_limit(account._credit_limit) {}
};

#endif //QUADROBANK_ACCOUNT_BALANCE_DTO_H
