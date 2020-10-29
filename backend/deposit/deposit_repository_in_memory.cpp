#include "deposit_repository_in_memory.h"

int DepositRepositoryInMemory::_freeId = 1;

DepositRepositoryInMemory::DepositRepositoryInMemory() {
    int curr_time = time(nullptr);
    int period_sec = 10;
    _deposits.push_back(
            Deposit{_get_free_id(), "1111 1111 1111 1111", 10, 5, curr_time, curr_time + period_sec, 100}
    );
}

void DepositRepositoryInMemory::_add(const Deposit &deposit) const {
    if(deposit._id == 0){
        Deposit copy(deposit);
        copy._id = _get_free_id();
        _deposits.push_back(copy);
    } else {
        _deposits.push_back(deposit);
    }
}

void DepositRepositoryInMemory::_remove(const int id) const {
    _deposits = _get_list(Specification<Deposit>([=] (const Deposit& d) { return d._id != id;}));
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
