#ifndef QUADROBANK_EXCEPTION_H
#define QUADROBANK_EXCEPTION_H

#include <bits/exception.h>
#include <string>
#include <utility>

using std::exception;
using std::string;

class Exception : public exception {

private:

    const string _message;

public:

    explicit Exception(string message) : _message(std::move(message)) {}

    const string &get_message() const {
        return _message;
    }
};

#endif //QUADROBANK_EXCEPTION_H
