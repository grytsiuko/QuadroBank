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
    const vector<string> COLUMNS{"id", "name"};
    const vector<string> COLUMNS_EXTENDED{
            "id INTEGER PRIMARY KEY AUTOINCREMENT",
            "name VARCHAR(255) NOT NULL"
    };

    friend Singleton;

    const DBService &_db_service;

    UserRepositoryDb() : _db_service(DBService::get_instance()) {
        _db_service.create_table_if_not_exists(TABLE, COLUMNS_EXTENDED);
        _seed_data();
    }

    Optional<User> _get_by_id(const int id) const override {
        Optional<map<string, QVariant>> res_optional = _db_service.select_one(
                TABLE, COLUMNS, "id=%0", {std::to_string(id)}
        );
        if (res_optional.is_empty()) {
            return Optional<User>::empty();
        }

        return Optional<User>::of(_get_entity_from_map(res_optional.get()));
    }

    void _seed_data() const {
        int count = _db_service.count(TABLE);
        if (count > 0) {
            return;
        }
        _db_service.insert(TABLE, COLUMNS, {"15", "'Petrov Petrov'"});
        _db_service.insert(TABLE, COLUMNS, {"20", "'Stepan Stepanenko'"});
    }

    User _get_entity_from_map(const map<string, QVariant> &data) const {
        return User{
                data.at("id").toInt(),
                data.at("name").toString().toStdString()
        };
    }
};

#endif //QUADROBANK_USER_REPOSITORY_DB_H
