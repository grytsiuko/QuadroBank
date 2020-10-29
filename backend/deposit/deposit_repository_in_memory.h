#ifndef QUADROBANK_DEPOSIT_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_DEPOSIT_REPOSITORY_IN_MEMORY_H

#include "model/deposit.h"
#include "deposit_repository_interface.h"
#include "../utils/singleton.h"
#include <ctime>

class DepositRepositoryInMemory : public DepositRepositoryInterface, public Singleton<DepositRepositoryInMemory> {

    friend Singleton;

private:
    mutable vector<Deposit> _deposits;
    static int _freeId;

    DepositRepositoryInMemory();

    void _add(const Deposit& deposit) const override;

    void _remove(int id) const override;

    vector<Deposit> _get_list(const Specification<Deposit>& deposit_specification) const override;

    int _get_free_id() const;
};

#endif //QUADROBANK_DEPOSIT_REPOSITORY_IN_MEMORY_H
