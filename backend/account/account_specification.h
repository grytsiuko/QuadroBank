#ifndef QUADROBANK_ACCOUNT_SPECIFICATION_H
#define QUADROBANK_ACCOUNT_SPECIFICATION_H

#include "../utils/non_copying.h"
#include "model/account.h"

class AccountSpecification : public NonCopying {

private:

    bool (*_filter)(const Account &);

public:

    explicit AccountSpecification(bool (*filter)(const Account &)) :
            _filter(filter) {};

    bool filter(const Account &account) const {
        return _filter(account);
    }

};

#endif //QUADROBANK_ACCOUNT_SPECIFICATION_H
