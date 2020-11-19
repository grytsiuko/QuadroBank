
#ifndef QUADROBANK_INTERNAL_DB_ERROR_H
#define QUADROBANK_INTERNAL_DB_ERROR_H

#include "exception.h"

class InternalDBError : public Exception {

private:

    const string _message = "Internal DB error";

    const string &_get_message() const override {
        return _message;
    }
};


#endif //QUADROBANK_INTERNAL_DB_ERROR_H
