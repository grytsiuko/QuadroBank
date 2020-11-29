#ifndef QUADROBANK_DEPOSIT_VARIANT_REPSITORY_INTERFACE_H
#define QUADROBANK_DEPOSIT_VARIANT_REPSITORY_INTERFACE_H

#include <vector>
#include "backend/db/specifications/specification.h"
#include "backend/deposit_variant/model/deposit_variant.h"

using std::vector;

class DepositVariantRepositoryInterface {

public:

    Optional<DepositVariant> get_by_percentage(const double percentage) const{
        return _get_by_percentage(percentage);
    }

    vector<DepositVariant> get_list(const Specification<DepositVariant>& deposit_variant_specification) const {
        return _get_list(deposit_variant_specification);
    }

private:

    virtual Optional<DepositVariant> _get_by_percentage(double percentage) const = 0;

    virtual vector<DepositVariant> _get_list(const Specification<DepositVariant> &deposit_variant_specification) const = 0;
};

#endif //QUADROBANK_DEPOSIT_VARIANT_REPSITORY_INTERFACE_H
