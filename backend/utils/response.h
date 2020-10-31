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

    Response &operator=(const Response &) = delete;

    Response(const Response &&response) noexcept: _value(response._value), _error(response._error) {
        response._value = nullptr;
        response._error = nullptr;
    }

    Response &operator=(Response &&response) noexcept {
        _value = response._value;
        _error = response._error;
        response._value = nullptr;
        response._error = nullptr;
        return *this;
    }

    static Response success(const T *value) {
        return Response(value, nullptr);
    }

    static Response error(const string *error) {
        return Response(nullptr, error);
    }

    bool is_success() const {
        return _value != nullptr;
    }

    bool is_error() const {
        return !is_success();
    }

    const T *get_response() const {
        return _value;
    }

    const string *get_error() const {
        return _error;
    }
};

template <>
class Response<void> {

private:

    mutable const string *_error;

    explicit Response(const string *error) : _error(error) {}

public:

    ~Response() {
        delete _error;
    }

    Response(const Response &) = delete;

    Response &operator=(const Response &) = delete;

    Response(const Response &&response) noexcept: _error(response._error) {
        response._error = nullptr;
    }

    Response &operator=(Response &&response) noexcept {
        _error = response._error;
        response._error = nullptr;
        return *this;
    }

    static Response success() {
        return Response(nullptr);
    }

    static Response error(const string *error) {
        return Response(error);
    }

    bool is_success() const {
        return _error == nullptr;
    }

    bool is_error() const {
        return !is_success();
    }

    const string *get_error() const {
        return _error;
    }
};

#endif //QUADROBANK_RESPONSE_H
