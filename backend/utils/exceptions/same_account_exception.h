
#ifndef QUADROBANK_SAME_ACCOUNT_EXCEPTION_H
#define QUADROBANK_SAME_ACCOUNT_EXCEPTION_H

#include "exception.h"

class SameAccountException : public Exception {

private:

    const string _message = "Unable to do this operation with the same account";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_SAME_ACCOUNT_EXCEPTION_H
