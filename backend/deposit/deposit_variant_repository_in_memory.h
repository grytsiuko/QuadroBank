#ifndef QUADROBANK_DEPOSIT_VARIANT_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_DEPOSIT_VARIANT_REPOSITORY_IN_MEMORY_H

#include "../utils/optional.h"
#include "deposit_variant_repsitory_interface.h"
#include "../utils/singleton.h"

class DepositVariantRepositoryInMemory :
        public DepositVariantRepositoryInterface,
        public Singleton<DepositVariantRepositoryInMemory> {

    friend Singleton;

private:
    mutable vector<DepositVariant> _deposit_variants;

    DepositVariantRepositoryInMemory();

    Optional<DepositVariant> _get_by_percentage(double percentage) const override;

    vector<DepositVariant> _get_list(const Specification<DepositVariant>& deposit_variant_specification) const override;
};

#endif //QUADROBANK_DEPOSIT_VARIANT_REPOSITORY_IN_MEMORY_H
