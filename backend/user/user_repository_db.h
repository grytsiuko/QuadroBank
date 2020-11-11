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

    const static string TABLE;
    const static vector<string> COLUMNS;
    const static vector<string> COLUMNS_EXTENDED;

    friend Singleton;

    const DBService &_db_service;

    UserRepositoryDb();

    Optional<User> _get_by_id(const int id) const override;

    void _seed_data() const;

    User _get_entity_from_map(const map<string, QVariant> &data) const;
};

#endif //QUADROBANK_USER_REPOSITORY_DB_H
