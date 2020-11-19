
#ifndef QUADROBANK_UNAUTHORIZED_EXCEPTION_H
#define QUADROBANK_UNAUTHORIZED_EXCEPTION_H

#include "exception.h"

class UnauthorizedException : public Exception {

private:

    const string _message = "Unauthorized!";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_UNAUTHORIZED_EXCEPTION_H
