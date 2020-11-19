
#ifndef QUADROBANK_NO_SUCH_USER_EXCEPTION_H
#define QUADROBANK_NO_SUCH_USER_EXCEPTION_H

#include "exception.h"

class NoSuchUserException : public Exception {

private:

    const string _message = "No user found";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_NO_SUCH_USER_EXCEPTION_H
