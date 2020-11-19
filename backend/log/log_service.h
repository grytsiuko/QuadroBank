#ifndef QUADROBANK_LOG_SERVICE_H
#define QUADROBANK_LOG_SERVICE_H

#include <string>
#include <iostream>
#include "../utils/singleton.h"

using std::string;
using std::cout;

class LogService : public Singleton<LogService> {

private:

    friend Singleton;

    LogService() = default;

public:

    void log(const string &prefix, const string &text) const;
};

#endif //QUADROBANK_LOG_SERVICE_H
