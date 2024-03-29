

#include "backend/utils/time_intervals.h"
#include "deposit_variant_repository_in_memory.h"

DepositVariantRepositoryInMemory::DepositVariantRepositoryInMemory() {
    _deposit_variants.push_back(DepositVariant{10 * TimeIntervals::SECOND, 0.01});
    _deposit_variants.push_back(DepositVariant{TimeIntervals::MINUTE, 0.1});
    _deposit_variants.push_back(DepositVariant{2 * TimeIntervals::MINUTE, 0.3});
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
            return Optional<DepositVariant>::of(deposit_variant);
        }
    }
    return Optional<DepositVariant>::empty();
}
