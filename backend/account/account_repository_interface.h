#ifndef QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H
#define QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H

#include <vector>
#include "../utils/optional.h"
#include "model/account.h"
#include "../utils/singleton.h"
#include "../db/specification.h"

using std::string;
using std::vector;

template <class T>
class AccountRepositoryInterface: public Singleton<T> {

public:

    vector<Account> get_list(const Specification<Account> &account_specification) const {
        return _get_list(account_specification);
    }

    Optional<Account> get_by_card_number(const string &card_number) const {
        return _get_by_card_number(card_number);
    }

    void update(const Account &account) const {
        return _update(account);
    }

private:

    virtual vector<Account> _get_list(const Specification<Account> &account_specification) const = 0;

    virtual Optional<Account> _get_by_card_number(const string &card_number) const = 0;

    virtual void _update(const Account &account) const = 0;
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H
