#ifndef QUADROBANK_SINGLETON_H
#define QUADROBANK_SINGLETON_H

#include "non_copying.h"

template<class T>
class Singleton : public NonCopying {

protected:

    Singleton() = default;

public:

    static T &get_instance() {
        static T instance;
        return instance;
    }
};

#endif //QUADROBANK_SINGLETON_H
