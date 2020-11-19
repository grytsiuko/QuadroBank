
#ifndef QUADROBANK_INTERNAL_ERROR_H
#define QUADROBANK_INTERNAL_ERROR_H

#include "exception.h"

class InternalError : public Exception {

private:

    const string _message = "Internal error";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_INTERNAL_ERROR_H
