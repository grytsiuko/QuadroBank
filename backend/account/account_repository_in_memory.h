#ifndef QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H

#include <vector>
#include "../utils/optional.h"
#include "model/account.h"
#include "account_repository_interface.h"

using std::string;
using std::vector;

class AccountRepositoryInMemory :
        public AccountRepositoryInterface,
        public Singleton<AccountRepositoryInMemory> {

private:

    friend Singleton;

    mutable vector<Account> _accounts;

    AccountRepositoryInMemory();


    vector<Account> _get_list(const Specification<Account> &account_specification) const override;

    Optional<Account> _get_by_card_number(const string &card_number) const override;

    void _update(const Account &account) const override;
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H
