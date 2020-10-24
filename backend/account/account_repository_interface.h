#ifndef QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H
#define QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H

#include "../utils/optional.h"
#include "model/account.h"

using std::string;

class AccountRepositoryInterface {

public:

    Optional<Account> get_by_card_number(const string &card_number) const {
        return _get_by_card_number(card_number);
    }

protected:

    AccountRepositoryInterface() = default;

    virtual ~AccountRepositoryInterface() = default;

    AccountRepositoryInterface(const AccountRepositoryInterface &) = default;

    AccountRepositoryInterface &operator=(const AccountRepositoryInterface &) = default;


private:

    virtual Optional<Account> _get_by_card_number(const string &card_number) const = 0;
};

#endif //QUADROBANK_ACCOUNT_REPOSITORY_INTERFACE_H
