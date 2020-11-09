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

class AccountRepositoryDb : public AccountRepositoryInterface<AccountRepositoryDb> {

private:

    const string TABLE = "accounts";

    friend Singleton;

    const DBService &_db_service;

    AccountRepositoryDb() : _db_service(DBService::get_instance()) {
        vector<string> fields{
                "card_number VARCHAR(255) PRIMARY KEY",
                "user_id INT NOT NULL",
                "pin VARCHAR(255) NOT NULL",
                "is_blocked BOOLEAN NOT NULL",
                "balance INT NOT NULL",
                "credit_limit INT NOT NULL",
                "credit_start INT NOT NULL"
        };
        _db_service.create_table_if_not_exists(TABLE, fields);
        _seed_data();
    }

    vector<Account> _get_list(const Specification<Account> &account_specification) const override {
        return vector<Account>();
    }

    Optional<Account> _get_by_card_number(const string &card_number) const override {
        return Optional<Account>::empty();
    }

    void _update(const Account &account) const override {
    }

    void _seed_data() const {
        int count = _db_service.count(TABLE);
        if (count > 0) {
            return;
        }
        vector<string> columns{"card_number", "user_id", "pin", "is_blocked",
                               "balance", "credit_limit", "credit_start"};
        _db_service.insert(
                TABLE, columns, vector<string>{"'1111111111111111'", "15", "'1111'", "0", "15000", "5000", "0"}
        );
        _db_service.insert(
                TABLE, columns, vector<string>{"'2222222222222222'", "15", "'2222'", "0", "20000", "0", "0"}
        );
        _db_service.insert(
                TABLE, columns, vector<string>{"'3333333333333333'", "20", "'3333'", "0", "0", "300", "0"}
        );
        _db_service.insert(
                TABLE, columns, vector<string>{"'1234123412341234'", "20", "'3333'", "0", "52000", "0", "0"}
        );
        _db_service.insert(
                TABLE, columns, vector<string>{"'4321432143214321'", "20", "'3333'", "0", "7400", "0", "0"}
        );
    }
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_DB_H
