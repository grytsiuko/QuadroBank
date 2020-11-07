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

    Account assert_account(const string &card_number) const {
        Optional<Account> account = _account_repository.get_by_card_number(card_number);

        if (account.is_empty()) {
            throw Exception("No such card number");
        }
        return account.get();
    }

    User assert_user(int user_id) const {
        Optional<User> user = _user_repository.get_by_id(user_id);

        if (user.is_empty()) {
            throw Exception("No user found");
        }
        return user.get();
    }
};

#endif //QUADROBANK_AUTH_SERVICE_H
