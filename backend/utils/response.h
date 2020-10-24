#ifndef QUADROBANK_RESPONSE_H
#define QUADROBANK_RESPONSE_H

#include <string>

using std::string;

template<class T>
class Response {

private:

    mutable const T *_value;
    mutable const string *_error;

    explicit Response(const T *value, const string *error) : _value(value), _error(error) {}

public:

    ~Response() {
        delete _value;
        delete _error;
    }

    Response(const Response &) = delete;

    Response(const Response &&response) noexcept: _value(response._value), _error(response._error) {
        response._value = nullptr;
        response._error = nullptr;
    }

    Response &operator=(const Response &) = delete;

    static Response of(const T *value) {
        return Response(value, nullptr);
    }

    static Response error(const string *error) {
        return Response(nullptr, error);
    }

    bool is_present() const {
        return _value != nullptr;
    }

    bool is_error() const {
        return !is_present();
    }

    const T *get_value() const {
        return _value;
    }

    const string *get_error() const {
        return _error;
    }
};

#endif //QUADROBANK_RESPONSE_H
