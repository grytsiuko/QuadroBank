#ifndef QUADROBANK_REGULAR_PAYMENT_REPOSITORY_INTERFACE_H
#define QUADROBANK_REGULAR_PAYMENT_REPOSITORY_INTERFACE_H

#include <vector>
#include <backend/utils/optional.h>
#include "backend/db/specifications/specification.h"
#include "model/regular_payment.h"

using std::vector;

class RegularPaymentRepositoryInterface {

public:

    Optional<RegularPayment> get_by_id(int id) const{
        return _get_by_id(id);
    }

    void add(const RegularPayment& regular_payment) const {
        _add(regular_payment);
    }

    int update(const RegularPayment& regular_payment) const {
        return _update(regular_payment);
    }

    int remove(const int id) const {
        return _remove(id);
    }

    vector<RegularPayment> get_list(const Specification<RegularPayment>& regular_payment_specification) const {
        return _get_list(regular_payment_specification);
    }

private:

    virtual Optional<RegularPayment> _get_by_id(int id) const = 0;

    virtual void _add(const RegularPayment& regular_payment) const = 0;

    virtual int _update(const RegularPayment& regular_payment) const = 0;

    virtual int _remove(int id) const = 0;

    virtual vector<RegularPayment> _get_list(const Specification<RegularPayment> &regular_payment_specification) const = 0;
};

#endif //QUADROBANK_REGULAR_PAYMENT_REPOSITORY_INTERFACE_H
