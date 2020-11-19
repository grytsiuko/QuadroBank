
#ifndef QUADROBANK_NON_POSITIVE_NUMBER_EXCEPTION_H
#define QUADROBANK_NON_POSITIVE_NUMBER_EXCEPTION_H

#include "exception.h"

class NonPositiveNumberException : public Exception {

private:

    const string _message = "This field accepts only positive numbers";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_NON_POSITIVE_NUMBER_EXCEPTION_H
