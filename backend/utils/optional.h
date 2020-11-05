#ifndef QUADROBANK_OPTIONAL_H
#define QUADROBANK_OPTIONAL_H

template<class T>
class Optional {

private:

    mutable const T *_value;

    explicit Optional(const T *value) {
        if(value == nullptr){
            _value = nullptr;
        } else {
            _value = new T(*value);
        }
    }

public:

    ~Optional() {
        delete _value;
    }

    Optional(const Optional &) = delete;

    Optional &operator=(const Optional &) = delete;

    Optional(const Optional &&optional) noexcept: _value(optional._value) {
        optional._value = nullptr;
    }

    Optional &operator=(Optional &&optional) noexcept {
        _value = optional._value;
        optional._value = nullptr;
    }

    static Optional of(const T &value) {
        return Optional(&value);
    }

    static Optional empty() {
        return Optional(nullptr);
    }

    bool is_present() const {
        return _value != nullptr;
    }

    bool is_empty() const {
        return !is_present();
    }

    const T &get() const {
        return *_value;
    }
};

#endif //QUADROBANK_OPTIONAL_H
