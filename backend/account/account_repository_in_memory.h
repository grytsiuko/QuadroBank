#ifndef QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H
#define QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H

#include <vector>
#include "../utils/optional.h"
#include "model/account.h"
#include "account_repository_interface.h"

using std::string;
using std::vector;

class AccountRepositoryInMemory : public AccountRepositoryInterface<AccountRepositoryInMemory> {

private:

    friend Singleton;

    mutable vector<Account> _accounts;

    AccountRepositoryInMemory() : _accounts(vector<Account>()) {
        _accounts.push_back(
                Account{"1111 1111 1111 1111", 15, "1111", true, 100, 50, 0}
        );
        _accounts.push_back(
                Account{"2222 2222 2222 2222", 16, "2222", false, 20000, 0, 0}
        );
        _accounts.push_back(
                Account{"3333 3333 3333 3333", 20, "3333", true, 0, 300, 0}
        );
        _accounts.push_back(
                Account{"1234", 21, "3333", true, 0, 300, 0}
        );
    }


    vector<Account> _get_list(const Specification<Account> &account_specification) const override {
        vector<Account> result = vector<Account>();
        for (const Account &account:_accounts) {
            if (account_specification.filter(account)) {
                result.push_back(account);
            }
        }
        return result;
    };

    Optional<Account> _get_by_card_number(const string &card_number) const override {
        for (const Account &account:_accounts) {
            if (account._card_number == card_number) {
                return Optional<Account>::of(account);
            }
        }
        return Optional<Account>::empty();
    };

    void _update(const Account &account) const override {
        for (Account &curr : _accounts) {
            if (curr._card_number == account._card_number) {
                curr = account;
                return;
            }
        }
    }
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_IN_MEMORY_H
