
#ifndef QUADROBANK_ILLEGAL_PIN_EXCEPTION_H
#define QUADROBANK_ILLEGAL_PIN_EXCEPTION_H

#include "exception.h"

class IllegalPinException : public Exception {

private:

    const string _message = "Illegal pin";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_ILLEGAL_PIN_EXCEPTION_H
