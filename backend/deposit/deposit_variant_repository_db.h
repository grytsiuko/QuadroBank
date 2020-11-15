#ifndef QUADROBANK_DEPOSIT_VARIANT_REPOSITORY_DB_H
#define QUADROBANK_DEPOSIT_VARIANT_REPOSITORY_DB_H

#include <string>
#include <vector>
#include <backend/db/db_service.h>
#include "deposit_variant_repsitory_interface.h"

using std::string;
using std::vector;

class DepositVariantRepositoryDb :
        public DepositVariantRepositoryInterface,
        public Singleton<DepositVariantRepositoryDb> {

private:

    const static string TABLE;
    const static vector<string> COLUMNS;
    const static vector<string> COLUMNS_EXTENDED;

    friend Singleton;

    const DBService &_db_service;

    DepositVariantRepositoryDb();

//    void _add(const Deposit& deposit) const override;
//
//    void _remove(int id) const override;
//
//    vector<Deposit> _get_list(const Specification<Deposit> &deposit_specification) const override;

    void _seed_data() const;

    DepositVariant _get_entity_from_map(const map<string, QVariant> &data) const;
};

#endif //QUADROBANK_DEPOSIT_VARIANT_REPOSITORY_DB_H
