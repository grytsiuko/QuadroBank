
#ifndef QUADROBANK_CREDIT_CARD_BALANCE_EXCEPTION_H
#define QUADROBANK_CREDIT_CARD_BALANCE_EXCEPTION_H

#include "exception.h"

class CreditCardBalanceException : public Exception {

private:

    const string _message = "You cannot exceed your credit limit";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_CREDIT_CARD_BALANCE_EXCEPTION_H
