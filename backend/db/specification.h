#ifndef QUADROBANK_SPECIFICATION_H
#define QUADROBANK_SPECIFICATION_H

#include <functional>
#include "../utils/non_copying.h"
#include "../account/model/account.h"

using std::function;

template <class T>
class Specification : public NonCopying {

private:

    const function<bool(const T&)> _filter;

public:

    explicit Specification(const function<bool(const T&)> filter) :
            _filter(std::move(filter)) {};

    bool filter(const T& t) const {
        return _filter(t);
    }

};

#endif //QUADROBANK_SPECIFICATION_H
