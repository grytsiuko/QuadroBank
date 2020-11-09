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

    friend Singleton;

    const  DBService &_db_service;

    UserRepositoryDb(): _db_service(DBService::get_instance()) {}

    Optional<User> _get_by_id(const int id) const override {
        return Optional<User>::empty();
    }
};

#endif //QUADROBANK_USER_REPOSITORY_DB_H
