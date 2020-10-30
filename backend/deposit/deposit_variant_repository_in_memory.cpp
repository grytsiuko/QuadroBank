

#include "deposit_variant_repository_in_memory.h"

DepositVariantRepositoryInMemory::DepositVariantRepositoryInMemory() {
    _deposit_variants.push_back(DepositVariant{100, 9});
    _deposit_variants.push_back(DepositVariant{1000, 10});
    _deposit_variants.push_back(DepositVariant{10000, 10.5});
    _deposit_variants.push_back(DepositVariant{3600*24*14, 12});
}

vector<DepositVariant>
DepositVariantRepositoryInMemory::_get_list(const Specification<DepositVariant> &deposit_variant_specification) const {
    vector<DepositVariant> result;
    for (const DepositVariant& deposit_variant : _deposit_variants) {
        if (deposit_variant_specification.filter(deposit_variant)) {
            result.push_back(deposit_variant);
        }
    }
    return result;
}

Optional<DepositVariant> DepositVariantRepositoryInMemory::_get_by_percentage(double percentage) const {
    for (const DepositVariant& deposit_variant : _deposit_variants) {
        if (deposit_variant._percentage == percentage) {
            return Optional<DepositVariant>::of(new DepositVariant(deposit_variant));
        }
    }
    return Optional<DepositVariant>::empty();
}
