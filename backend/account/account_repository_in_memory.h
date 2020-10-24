#ifndef QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H

#include <vector>
#include "../utils/optional.h"
#include "model/account.h"
#include "account_repository_interface.h"

using std::string;
using std::vector;

class AccountRepositoryInMemory: public AccountRepositoryInterface<AccountRepositoryInMemory> {

private:

    friend Singleton;

    vector<Account> _accounts;

    AccountRepositoryInMemory(): _accounts(vector<Account>()) {
        _accounts.push_back(Account{"1111 1111 1111 1111", "1111"});
        _accounts.push_back(Account{"2222 2222 2222 2222", "2222"});
        _accounts.push_back(Account{"3333 3333 3333 3333", "3333"});
    }

    Optional<Account> _get_by_card_number(const string &card_number) const override {
        for (const Account &account:_accounts){
            if (account._card_number == card_number) {
                return Optional<Account>::of(new Account(account));
            }
        }
        return Optional<Account>::empty();
    };
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H
