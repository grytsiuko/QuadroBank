#ifndef QUADROBANK_REGULAR_PAYMENT_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_REGULAR_PAYMENT_REPOSITORY_IN_MEMORY_H


#include "regular_payment_repository_interface.h"
#include "backend/utils/singleton.h"

class RegularPaymentRepositoryInMemory : public RegularPaymentRepositoryInterface, public Singleton<RegularPaymentRepositoryInMemory> {

    friend Singleton;

private:
    mutable vector<RegularPayment> _regular_payments;
    static int _freeId;

    RegularPaymentRepositoryInMemory();

    void _add(const RegularPayment& regular_payment) const override;

    void _update(const RegularPayment& regular_payment) const override;

    void _remove(int id) const override;

    vector<RegularPayment> _get_list(const Specification<RegularPayment>& regular_payment_specification) const override;

    int _get_free_id() const;
};

#endif //QUADROBANK_REGULAR_PAYMENT_REPOSITORY_IN_MEMORY_H
