#ifndef QUADROBANK_USER_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_USER_REPOSITORY_IN_MEMORY_H

#include <vector>
#include "../utils/optional.h"
#include "model/user.h"
#include "user_repository_interface.h"

using std::string;
using std::vector;

class UserRepositoryInMemory : public UserRepositoryInterface<UserRepositoryInMemory> {

private:

    friend Singleton;

    mutable vector<User> _users;

    UserRepositoryInMemory() : _users(vector<User>()) {
        _users.push_back(
                User{15, "Petro Petrov"}
        );
        _users.push_back(
                User{20, "Stepan Stepanenko"}
        );
    }

    Optional<User> _get_by_id(const int id) const override {
        for (const User &user:_users) {
            if (user._id == id) {
                return Optional<User>::of(new User(user));
            }
        }
        return Optional<User>::empty();
    };
};

#endif //QUADROBANK_USER_REPOSITORY_IN_MEMORY_H
