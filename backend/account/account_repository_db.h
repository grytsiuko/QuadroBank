#ifndef QUADROBANK_ACCOUNT_REPOSITORY_DB_H
#define QUADROBANK_ACCOUNT_REPOSITORY_DB_H

#include <string>
#include <vector>
#include <backend/utils/singleton.h>
#include <backend/db/db_service.h>
#include <backend/user/user_repository_db.h>
#include "account_repository_interface.h"

using std::string;
using std::vector;

class AccountRepositoryDb :
        public AccountRepositoryInterface<AccountRepositoryDb>,
        public Singleton<AccountRepositoryDb> {

private:

    const static string TABLE;
    const static vector<string> COLUMNS;
    const static vector<string> COLUMNS_EXTENDED;

    friend Singleton;

    const DBService &_db_service;

    AccountRepositoryDb();

    vector<Account> _get_list(const Specification<Account> &account_specification) const override;

    Optional<Account> _get_by_card_number(const string &card_number) const override;

    void _update(const Account &account) const override;

    void _seed_data() const;

    Account _get_entity_from_map(const map<string, QVariant> &data) const;
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_DB_H
