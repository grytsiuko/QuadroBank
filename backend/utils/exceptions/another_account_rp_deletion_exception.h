
#ifndef QUADROBANK_ANOTHER_ACCOUNT_RP_DELETION_EXCEPTION_H
#define QUADROBANK_ANOTHER_ACCOUNT_RP_DELETION_EXCEPTION_H

#include "exception.h"

class AnotherAccountRPDeletionException : public Exception {

private:

    const string _message = "Attempt to delete someone else's regular payment";

    const string &_get_message() const override {
        return _message;
    }
};


#endif //QUADROBANK_ANOTHER_ACCOUNT_RP_DELETION_EXCEPTION_H
