#ifndef QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H
#define QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H

#include "../utils/optional.h"
#include "model/account.h"
#include "../utils/singleton.h"

using std::string;

template <class T>
class AccountRepositoryInterface: public Singleton<T> {

public:

    Optional<Account> get_by_card_number(const string &card_number) const {
        return _get_by_card_number(card_number);
    }

    void update(const Account &account) const {
        return _update(account);
    }

private:

    virtual Optional<Account> _get_by_card_number(const string &card_number) const = 0;

    virtual void _update(const Account &account) const = 0;
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H
