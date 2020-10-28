#ifndef QUADROBANK_DEPOSIT_REPOSITORY_INTERFACE_H
#define QUADROBANK_DEPOSIT_REPOSITORY_INTERFACE_H

#include <vector>
#include "model/deposit.h"
#include "../utils/singleton.h"
#include "../db/specification.h"

using std::vector;

template <class T>
class DepositRepositoryInterface: public Singleton<T> {

public:

    void add(const Deposit& deposit) const {
        _add(deposit);
    }

    void remove(const Deposit& deposit) const {
        _remove(deposit);
    }

    vector<Deposit> get_list(const Specification<Deposit>& deposit_specification) const {
        return _get_list(deposit_specification);
    }

private:

    virtual void _add(Deposit& deposit) const = 0;

    virtual void _remove(Deposit& deposit) const = 0;

    virtual vector<Deposit> _get_list(const Specification<Deposit> &deposit_specification) const = 0;
};

#endif //QUADROBANK_DEPOSIT_REPOSITORY_INTERFACE_H