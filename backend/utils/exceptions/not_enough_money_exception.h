
#ifndef QUADROBANK_NOT_ENOUGH_MONEY_EXCEPTION_H
#define QUADROBANK_NOT_ENOUGH_MONEY_EXCEPTION_H

#include "exception.h"

class NotEnoughMoneyException : public Exception {

private:

    const string _message = "Not enough money";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_NOT_ENOUGH_MONEY_EXCEPTION_H
