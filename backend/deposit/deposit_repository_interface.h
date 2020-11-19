#ifndef QUADROBANK_DEPOSIT_REPOSITORY_INTERFACE_H
#define QUADROBANK_DEPOSIT_REPOSITORY_INTERFACE_H

#include <vector>
#include "model/deposit.h"
#include "../utils/singleton.h"
#include "backend/db/specifications/specification.h"


using std::vector;

class DepositRepositoryInterface {

public:

    void add(const Deposit& deposit) const {
        _add(deposit);
    }

    void remove(const int id) const {
        _remove(id);
    }

    vector<Deposit> get_list(const Specification<Deposit>& deposit_specification) const {
        return _get_list(deposit_specification);
    }

private:

    virtual void _add(const Deposit& deposit) const = 0;

    virtual void _remove(int id) const = 0;

    virtual vector<Deposit> _get_list(const Specification<Deposit> &deposit_specification) const = 0;
};

#endif //QUADROBANK_DEPOSIT_REPOSITORY_INTERFACE_H
