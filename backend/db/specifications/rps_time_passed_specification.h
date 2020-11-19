
#ifndef QUADROBANK_RPS_TIME_PASSED_SPECIFICATION_H
#define QUADROBANK_RPS_TIME_PASSED_SPECIFICATION_H

#include "specification.h"
#include <backend/utils/string_convert.h>
#include <backend/regular_payment/model/regular_payment.h>

class RPsTimePassedSpecification: public Specification<RegularPayment> {

private:
    const time_t _time;
    const string _where = "next_time < %0";
    const vector<string> _params;

public:
    explicit RPsTimePassedSpecification(const time_t time) : _time(time), _params({to_param(_time)}){}

private:
    bool _filter(const RegularPayment &rp) const override {
        return rp._next_time < _time;
    }

    const string &_get_where() const override {
        return _where;
    }

    const vector<string> &_get_params() const override {
        return _params;
    }
};

#endif //QUADROBANK_RPS_TIME_PASSED_SPECIFICATION_H
