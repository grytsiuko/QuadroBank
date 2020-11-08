
#include "account_repository_in_memory.h"

AccountRepositoryInMemory::AccountRepositoryInMemory() : _accounts(vector<Account>()) {
    _accounts.push_back(
            Account{"1111111111111111", 15, "1111", false, 15000, 5000, 0}
    );
    _accounts.push_back(
            Account{"2222222222222222", 15, "2222", false, 20000, 0, 0}
    );
    _accounts.push_back(
            Account{"3333333333333333", 20, "3333", false, 0, 300, 0}
    );
    _accounts.push_back(
            Account{"1234123412341234", 20, "3333", false, 52000, 0, 0}
    );
    _accounts.push_back(
            Account{"4321432143214321", 20, "3333", false, 7400, 0, 0}
    );
}


vector<Account> AccountRepositoryInMemory::_get_list(const Specification<Account> &account_specification) const {
    vector<Account> result = vector<Account>();
    for (const Account &account:_accounts) {
        if (account_specification.filter(account)) {
            result.push_back(account);
        }
    }
    return result;
}

Optional<Account> AccountRepositoryInMemory::_get_by_card_number(const string &card_number) const {
    for (const Account &account:_accounts) {
        if (account._card_number == card_number) {
            return Optional<Account>::of(account);
        }
    }
    return Optional<Account>::empty();
}

void AccountRepositoryInMemory::_update(const Account &account) const {
    for (Account &curr : _accounts) {
        if (curr._card_number == account._card_number) {
            curr = account;
            return;
        }
    }
}


