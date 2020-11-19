#include <backend/utils/exception.h>
#include <backend/db/specifications/deposits_all_except_this_specification.h>
#include "deposit_repository_in_memory.h"
#include "backend/utils/time_intervals.h"

int DepositRepositoryInMemory::_freeId = 1;

DepositRepositoryInMemory::DepositRepositoryInMemory() {
    int curr_time = time(nullptr);
    int period_sec = 10 * TimeIntervals::SECOND;
}

void DepositRepositoryInMemory::_add(const Deposit &deposit) const {
    if(deposit._id == 0){
        Deposit copy(deposit);
        copy._id = _get_free_id();
        _deposits.push_back(copy);
    } else {
        throw Exception("An attempt to create deposit with possibly wrong id");
    }
}

void DepositRepositoryInMemory::_remove(const int id) const {
    _deposits = _get_list(DepositsAllExceptThisSpecification(id));
}

vector<Deposit> DepositRepositoryInMemory::_get_list(const Specification<Deposit> &deposit_specification) const {
    vector<Deposit> result;
    for (const Deposit& deposit : _deposits) {
        if (deposit_specification.filter(deposit)) {
            result.push_back(deposit);
        }
    }
    return result;
}

int DepositRepositoryInMemory::_get_free_id() const {
    return _freeId++;
}
