
#ifndef QUADROBANK_BLOCKED_CARD_EXCEPTION_H
#define QUADROBANK_BLOCKED_CARD_EXCEPTION_H

#include "exception.h"

class BlockedCardException : public Exception {

private:

    const string _message = "This card is blocked, contact the nearest bank branch to fix it";

    const string &_get_message() const override {
        return _message;
    }
};

#endif //QUADROBANK_BLOCKED_CARD_EXCEPTION_H
