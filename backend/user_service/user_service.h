#ifndef QUADROBANK_USER_SERVICE_H
#define QUADROBANK_USER_SERVICE_H

#include "user_repository.h"

class UserService {

private:

    UserRepository user_repository;

public:

    UserService() : user_repository(UserRepository()) {}

    void test_connection() {
        user_repository.test_connection();
    }
};

#endif
