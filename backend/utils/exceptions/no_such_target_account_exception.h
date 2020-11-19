
#ifndef QUADROBANK_NO_SUCH_TARGET_ACCOUNT_EXCEPTION_H
#define QUADROBANK_NO_SUCH_TARGET_ACCOUNT_EXCEPTION_H

#include "exception.h"

class NoSuchTargetAccountException : public Exception {

private:

    const string _message = "Target account does not exists";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_NO_SUCH_TARGET_ACCOUNT_EXCEPTION_H
