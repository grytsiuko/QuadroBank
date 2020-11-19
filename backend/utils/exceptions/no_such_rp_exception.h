
#ifndef QUADROBANK_NO_SUCH_RP_EXCEPTION_H
#define QUADROBANK_NO_SUCH_RP_EXCEPTION_H

#include "exception.h"

class NoSuchRPException : public Exception {

private:

    const string _message = "Regular payment does not exists";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_NO_SUCH_RP_EXCEPTION_H
