
#ifndef QUADROBANK_DEPOSITS_BEFORE_TIME_SPECIFICATION_H
#define QUADROBANK_DEPOSITS_BEFORE_TIME_SPECIFICATION_H

#include <backend/deposit/model/deposit.h>
#include <utility>
#include "specification.h"
#include <backend/utils/string_convert.h>

class DepositsBeforeTimeSpecification: public Specification<Deposit> {

private:
    const time_t _time;
    const string _where = "end_date < %0";
    const vector<string> _params;

public:
    explicit DepositsBeforeTimeSpecification(const time_t time): _time(time), _params({to_param(_time)}){}

private:
    bool _filter(const Deposit &d) const override {
        return d._end_date < _time;
    }

    const string &_get_where() const override {
        return _where;
    }

    const vector<string> &_get_params() const override {
        return _params;
    }
};

#endif //QUADROBANK_DEPOSITS_BEFORE_TIME_SPECIFICATION_H
