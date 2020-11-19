
#ifndef QUADROBANK_PAST_DATE_EXCEPTION_H
#define QUADROBANK_PAST_DATE_EXCEPTION_H

#include "exception.h"

class PastDateException : public Exception {

private:

    const string _message = "This date should be in the future";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_PAST_DATE_EXCEPTION_H
