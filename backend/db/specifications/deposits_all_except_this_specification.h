
#ifndef QUADROBANK_DEPOSITS_ALL_EXCEPT_THIS_SPECIFICATION_H
#define QUADROBANK_DEPOSITS_ALL_EXCEPT_THIS_SPECIFICATION_H


#include <backend/deposit/model/deposit.h>
#include <utility>
#include "specification.h"
#include <backend/utils/string_convert.h>

class DepositsAllExceptThisSpecification: public Specification<Deposit> {

private:
    const int _id;
    const string _where = "id!=%0";
    const vector<string> _params = {int_param(_id)};

public:
    explicit DepositsAllExceptThisSpecification(const int id): _id(id){}

private:
    bool _filter(const Deposit &d) const override {
        return d._id != _id;
    }

    const string &_get_where() const override {
        return _where;
    }

    const vector<string> &_get_params() const override {
        return _params;
    }
};

#endif //QUADROBANK_DEPOSITS_ALL_EXCEPT_THIS_SPECIFICATION_H
