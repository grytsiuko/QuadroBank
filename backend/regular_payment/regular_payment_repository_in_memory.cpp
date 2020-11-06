
#include "regular_payment_repository_in_memory.h"
#include "backend/utils/exception.h"

int RegularPaymentRepositoryInMemory::_freeId = 1;

RegularPaymentRepositoryInMemory::RegularPaymentRepositoryInMemory() = default;

Optional<RegularPayment> RegularPaymentRepositoryInMemory::_get_by_id(int id) const{
    for(RegularPayment& rp : _regular_payments){
        if(rp._id == id){
            return Optional<RegularPayment>::of(&rp);
        }
    }
    return Optional<RegularPayment>::empty();
}

void RegularPaymentRepositoryInMemory::_add(const RegularPayment &regular_payment) const {
    if (regular_payment._id == 0) {
        RegularPayment copy(regular_payment);
        copy._id = _get_free_id();
        _regular_payments.push_back(copy);
    } else {
        throw Exception("Internal error: an attempt to create regular payment with possibly wrong id");
    }
}

void RegularPaymentRepositoryInMemory::_update(const RegularPayment &regular_payment) const {
    for (RegularPayment &rp : _regular_payments) {
        if (rp._id == regular_payment._id) {
            rp = regular_payment;
            return;
        }
    }
}

void RegularPaymentRepositoryInMemory::_remove(int id) const {
    _regular_payments = _get_list(
            Specification<RegularPayment>([=](const RegularPayment &rp) { return rp._id != id; }));
}

vector<RegularPayment>
RegularPaymentRepositoryInMemory::_get_list(const Specification<RegularPayment> &regular_payment_specification) const {
    vector<RegularPayment> result;
    for (const RegularPayment &rp : _regular_payments) {
        if (regular_payment_specification.filter(rp)) {
            result.push_back(rp);
        }
    }
    return result;
}

int RegularPaymentRepositoryInMemory::_get_free_id() const {
    return _freeId++;
}
