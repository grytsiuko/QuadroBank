
#include "user_repository_in_memory.h"

UserRepositoryInMemory::UserRepositoryInMemory() : _users(vector<User>()) {
    _users.push_back(
            User{15, "Petro Petrov"}
    );
    _users.push_back(
            User{20, "Stepan Stepanenko"}
    );
}

Optional<User> UserRepositoryInMemory::_get_by_id(const int id) const {
    for (const User &user:_users) {
        if (user._id == id) {
            return Optional<User>::of(user);
        }
    }
    return Optional<User>::empty();
}

