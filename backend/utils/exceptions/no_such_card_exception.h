
#ifndef QUADROBANK_NO_SUCH_CARD_EXCEPTION_H
#define QUADROBANK_NO_SUCH_CARD_EXCEPTION_H

#include "exception.h"

class NoSuchCardException : public Exception {

private:

    const string _message = "No such card number";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_NO_SUCH_CARD_EXCEPTION_H
