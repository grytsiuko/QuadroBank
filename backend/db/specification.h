#ifndef QUADROBANK_SPECIFICATION_H
#define QUADROBANK_SPECIFICATION_H

#include "../utils/non_copying.h"
#include "../account/model/account.h"

template <class T>
class Specification : public NonCopying {

private:

    bool (*_filter)(const T &);

public:

    explicit Specification(bool (*filter)(const T &)) :
            _filter(filter) {};

    bool filter(const T &t) const {
        return _filter(t);
    }

};

#endif //QUADROBANK_SPECIFICATION_H
