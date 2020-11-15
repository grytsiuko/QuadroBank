#ifndef QUADROBANK_REGULAR_PAYMENT_REPOSITORY_DB_H
#define QUADROBANK_REGULAR_PAYMENT_REPOSITORY_DB_H

#include <string>
#include <vector>
#include <backend/db/db_service.h>
#include "regular_payment_repository_interface.h"

using std::string;
using std::vector;

class RegularPaymentRepositoryDb :
        public RegularPaymentRepositoryInterface,
        public Singleton<RegularPaymentRepositoryDb> {

private:

    const static string TABLE;
    const static vector<string> COLUMNS;
    const static vector<string> COLUMNS_EXTENDED;

    friend Singleton;

    const DBService &_db_service;

    RegularPaymentRepositoryDb();

//    Optional<RegularPayment> _get_by_id(int id) const override;
//
//    void _add(const RegularPayment& regular_payment) const override;
//
//    int _update(const RegularPayment& regular_payment) const override;
//
//    int _remove(int id) const override;
//
//    vector<RegularPayment> _get_list(const Specification<RegularPayment> &regular_payment_specification) const override;

    void _seed_data() const;

    RegularPayment _get_entity_from_map(const map<string, QVariant> &data) const;
};

#endif //QUADROBANK_REGULAR_PAYMENT_REPOSITORY_DB_H
