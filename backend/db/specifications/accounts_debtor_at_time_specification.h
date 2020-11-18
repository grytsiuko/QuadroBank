
#ifndef QUADROBANK_ACCOUNTS_DEBTOR_AT_TIME_SPECIFICATION_H
#define QUADROBANK_ACCOUNTS_DEBTOR_AT_TIME_SPECIFICATION_H

#include "specification.h"
#include <backend/utils/string_convert.h>
#include <backend/account/model/account.h>

class AccountsDebtorAtTimeSpecification : public Specification<Account> {

private:
    const time_t _time;
    const time_t _non_credit_seconds;
    const string _where = "credit_start <> 0 AND credit_start + %0 < %1";
    const vector<string> _params = {to_param(_non_credit_seconds), to_param(_time)};

public:
    explicit AccountsDebtorAtTimeSpecification(const time_t non_credit_seconds, const time_t time) :
            _non_credit_seconds(non_credit_seconds), _time(time) {}

private:
    bool _filter(const Account &a) const override {
        return a._credit_start != 0 && a._credit_start + _non_credit_seconds < _time;
    }

    const string &_get_where() const override {
        return _where;
    }

    const vector<string> &_get_params() const override {
        return _params;
    }
};

#endif //QUADROBANK_ACCOUNTS_DEBTOR_AT_TIME_SPECIFICATION_H
