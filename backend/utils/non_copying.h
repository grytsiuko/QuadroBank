#ifndef QUADROBANK_NON_COPYING_H
#define QUADROBANK_NON_COPYING_H

class NonCopying {

public:

    NonCopying() = default;

    virtual ~NonCopying() = default;

    NonCopying &operator=(const NonCopying &) = delete;

    NonCopying &operator=(NonCopying &&) = delete;

    NonCopying(const NonCopying &) = delete;

    NonCopying(NonCopying &&) = delete;
};

#endif //QUADROBANK_NON_COPYING_H
