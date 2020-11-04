#ifndef QUADROBANK_REGULAR_PAYMENT_REPOSITORY_INTERFACE_H
#define QUADROBANK_REGULAR_PAYMENT_REPOSITORY_INTERFACE_H

#include <vector>
#include "backend/db/specification.h"
#include "model/regular_payment.h"

using std::vector;

class RegularPaymentRepositoryInterface {

public:

    void add(const RegularPayment& regular_payment) const {
        _add(regular_payment);
    }

    void update(const RegularPayment& regular_payment) const {
        _update(regular_payment);
    }

    void remove(const int id) const {
        _remove(id);
    }

    vector<RegularPayment> get_list(const Specification<RegularPayment>& regular_payment_specification) const {
        return _get_list(regular_payment_specification);
    }

private:

    virtual void _add(const RegularPayment& regular_payment) const = 0;

    virtual void _update(const RegularPayment& regular_payment) const = 0;

    virtual void _remove(int id) const = 0;

    virtual vector<RegularPayment> _get_list(const Specification<RegularPayment> &regular_payment_specification) const = 0;
};

#endif //QUADROBANK_REGULAR_PAYMENT_REPOSITORY_INTERFACE_H
