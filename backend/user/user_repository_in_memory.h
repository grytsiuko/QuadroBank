#ifndef QUADROBANK_USER_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_USER_REPOSITORY_IN_MEMORY_H

#include <vector>
#include "../utils/optional.h"
#include "model/user.h"
#include "user_repository_interface.h"

using std::string;
using std::vector;

class UserRepositoryInMemory :
        public UserRepositoryInterface,
        public Singleton<UserRepositoryInMemory> {

private:

    friend Singleton;

    mutable vector<User> _users;

    UserRepositoryInMemory();

    Optional<User> _get_by_id(const int id) const override;
};

#endif //QUADROBANK_USER_REPOSITORY_IN_MEMORY_H
