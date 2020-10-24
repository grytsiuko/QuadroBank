#ifndef QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H

#include "../utils/optional.h"
#include "model/account.h"
#include "account_repository_interface.h"

using std::string;

class AccountRepositoryInMemory: public AccountRepositoryInterface {

private:

    Optional<Account> _get_by_card_number(const string &card_number) const override {
        return Optional<Account>::empty();
    };

    AccountRepositoryInMemory() = default;

    ~AccountRepositoryInMemory() override = default;

public:

    AccountRepositoryInMemory(const AccountRepositoryInMemory &) = delete;

    AccountRepositoryInMemory &operator=(const AccountRepositoryInMemory &) = delete;

    static AccountRepositoryInMemory &get_instance() {
        static AccountRepositoryInMemory instance;
        return instance;
    }
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H
