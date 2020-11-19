
#ifndef QUADROBANK_DEPOSIT_FOR_CREDIT_EXCEPTION_H
#define QUADROBANK_DEPOSIT_FOR_CREDIT_EXCEPTION_H

#include "exception.h"

class DepositForCreditException : public Exception {

private:

    const string _message = "Unable to create deposits for credit cards";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_DEPOSIT_FOR_CREDIT_EXCEPTION_H
