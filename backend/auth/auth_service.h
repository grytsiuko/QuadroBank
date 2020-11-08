#ifndef QUADROBANK_AUTH_SERVICE_H
#define QUADROBANK_AUTH_SERVICE_H

#include <string>
#include <iostream>
#include <backend/account/model/account.h>
#include <backend/user/model/user.h>
#include <backend/account/account_repository_interface.h>
#include <backend/account/account_repository_in_memory.h>
#include <backend/utils/exception.h>
#include <backend/user/user_repository_interface.h>
#include <backend/user/user_repository_in_memory.h>
#include "../utils/singleton.h"

using std::string;
using std::cout;

class AuthService : public Singleton<AuthService> {

private:

    friend Singleton;

    const AccountRepositoryInterface<AccountRepositoryInMemory> &_account_repository;
    const UserRepositoryInterface<UserRepositoryInMemory> &_user_repository;

    AuthService():
            _account_repository(AccountRepositoryInterface<AccountRepositoryInMemory>::get_instance()),
            _user_repository(UserRepositoryInterface<UserRepositoryInMemory>::get_instance()) {}

public:

    Account assert_account(const string &card_number) const;

    User assert_user(int user_id) const;
};

#endif //QUADROBANK_AUTH_SERVICE_H
