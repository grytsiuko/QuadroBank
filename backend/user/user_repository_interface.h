#ifndef QUADROBANK_USER_REPOSITORY_INTERFACE_H
#define QUADROBANK_USER_REPOSITORY_INTERFACE_H

#include "../utils/singleton.h"
#include "../utils/optional.h"
#include "model/user.h"

class UserRepositoryInterface {

public:

    Optional<User> get_by_id(const int id) const {
        return _get_by_id(id);
    }

private:

    virtual Optional<User> _get_by_id(int id) const = 0;
};

#endif //QUADROBANK_USER_REPOSITORY_INTERFACE_H
