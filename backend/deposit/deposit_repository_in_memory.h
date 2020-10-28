#ifndef QUADROBANK_DEPOSIT_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_DEPOSIT_REPOSITORY_IN_MEMORY_H

#include "model/deposit.h"
#include "deposit_repository_interface.h"
#include "../utils/singleton.h"
#include <ctime>

class DepositRepositoryInMemory : public DepositRepositoryInterface<DepositRepositoryInMemory> {

private:

    friend Singleton;

    mutable vector<Deposit> _deposits;

    DepositRepositoryInMemory() {
        int curr_time = time(nullptr);
        _deposits.push_back(
                Deposit{1, "1111 1111 1111 1111", 10, 5, curr_time, curr_time+5, 100}
        );
    }

    void _add(Deposit& deposit) const override {
        _deposits.push_back(deposit);
    }

    void _remove(Deposit& deposit) const override {
        vector<Deposit> result;
        for (const Deposit& in_mem_deposist : _deposits) {
            if (deposit._id != in_mem_deposist._id) {
                result.push_back(deposit);
            }
        }
        _deposits = result;
//        _deposits = _get_list(Specification<Deposit>([&] (const Deposit& d) { return d._id != deposit._id;})); todo std::function in specification.h
    }

    vector<Deposit> _get_list(const Specification<Deposit>& deposit_specification) const override {
        vector<Deposit> result;
        for (const Deposit& deposit : _deposits) {
            if (deposit_specification.filter(deposit)) {
                result.push_back(deposit);
            }
        }
        return result;
    };
};

#endif //QUADROBANK_DEPOSIT_REPOSITORY_IN_MEMORY_H
