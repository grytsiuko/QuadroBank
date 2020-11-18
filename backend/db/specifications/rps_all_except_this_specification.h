
#ifndef QUADROBANK_RPS_ALL_EXCEPT_THIS_SPECIFICATION_H
#define QUADROBANK_RPS_ALL_EXCEPT_THIS_SPECIFICATION_H

#include "specification.h"
#include <backend/utils/string_convert.h>
#include <backend/regular_payment/model/regular_payment.h>

class RPsAllExceptThisSpecification: public Specification<RegularPayment> {

private:
    const int _id;
    const string _where = "id <> %0";
    const vector<string> _params = {to_param(_id)};

public:
    explicit RPsAllExceptThisSpecification(const int id): _id(id){}

private:
    bool _filter(const RegularPayment &rp) const override {
        return _id != rp._id;
    }

    const string &_get_where() const override {
        return _where;
    }

    const vector<string> &_get_params() const override {
        return _params;
    }
};

#endif //QUADROBANK_RPS_ALL_EXCEPT_THIS_SPECIFICATION_H
