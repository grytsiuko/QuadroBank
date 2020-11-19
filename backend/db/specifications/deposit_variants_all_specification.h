
#ifndef QUADROBANK_DEPOSIT_VARIANTS_ALL_SPECIFICATION_H
#define QUADROBANK_DEPOSIT_VARIANTS_ALL_SPECIFICATION_H

#include "specification.h"
#include <backend/deposit/model/deposit_variant.h>
#include <backend/utils/string_convert.h>

class DepositVariantsAllSpecification: public Specification<DepositVariant> {

private:

    const string _where = "";
    const vector<string> _params = {};

private:
    bool _filter(const DepositVariant &d) const override {
        return true;
    }

    const string &_get_where() const override {
        return _where;
    }

    const vector<string> &_get_params() const override {
        return _params;
    }
};

#endif //QUADROBANK_DEPOSIT_VARIANTS_ALL_SPECIFICATION_H
