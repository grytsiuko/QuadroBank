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

private:

    virtual Optional<Account> _get_by_card_number(const string &card_number) const = 0;
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H
