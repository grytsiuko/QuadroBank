
#ifndef QUADROBANK_SIMPLE_CARD_BALANCE_EXCEPTION_H
#define QUADROBANK_SIMPLE_CARD_BALANCE_EXCEPTION_H

#include "exception.h"

class SimpleCardBalanceException : public Exception {

private:

    const string _message = "You have simple card, you cannot have negative balance";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_SIMPLE_CARD_BALANCE_EXCEPTION_H
