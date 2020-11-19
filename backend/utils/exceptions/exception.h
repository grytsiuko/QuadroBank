#ifndef QUADROBANK_EXCEPTION_H
#define QUADROBANK_EXCEPTION_H

#include <exception>
#include <string>
#include <utility>

using std::exception;
using std::string;

class Exception : public exception {

public:

    const string &get_message() const {
        return _get_message();
    }

private:
    virtual const string &_get_message() const = 0;

};

#endif //QUADROBANK_EXCEPTION_H
