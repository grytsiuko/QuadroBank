#ifndef QUADROBANK_USER_REPOSITORY_DB_H
#define QUADROBANK_USER_REPOSITORY_DB_H

#include <string>
#include <vector>
#include <backend/user/model/user.h>
#include <backend/utils/singleton.h>
#include <backend/db/db_service.h>
#include "user_repository_interface.h"

using std::string;
using std::vector;

class UserRepositoryDb : public UserRepositoryInterface<UserRepositoryDb> {

private:

    const string TABLE = "users";

    friend Singleton;

    const DBService &_db_service;

    UserRepositoryDb() : _db_service(DBService::get_instance()) {
        vector<string> fields{
                "id INTEGER PRIMARY KEY AUTOINCREMENT",
                "name VARCHAR(255) NOT NULL"
        };
        _db_service.create_table_if_not_exists(TABLE, fields);
        _seed_data();
    }

    Optional<User> _get_by_id(const int id) const override {
        return Optional<User>::empty();
    }

    void _seed_data() const {
        int count = _db_service.count(TABLE);
        if (count > 0) {
            return;
        }
        _db_service.insert(TABLE, vector<string>{"id", "name"}, vector<string>{"15", "'Petrov Petrov'"});
        _db_service.insert(TABLE, vector<string>{"id", "name"}, vector<string>{"20", "'Stepan Stepanenko'"});
    }
};

#endif //QUADROBANK_USER_REPOSITORY_DB_H
