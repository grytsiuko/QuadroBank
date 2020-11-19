
#ifndef QUADROBANK_ILLEGAL_PERCENTAGE_EXCEPTION_H
#define QUADROBANK_ILLEGAL_PERCENTAGE_EXCEPTION_H

#include "exception.h"

class IllegalPercentageException : public Exception {

private:

    const string _message = "Illegal percentage";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_ILLEGAL_PERCENTAGE_EXCEPTION_H
