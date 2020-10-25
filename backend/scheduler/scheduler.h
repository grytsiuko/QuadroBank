#ifndef QUADROBANK_SCHEDULER_H
#define QUADROBANK_SCHEDULER_H

#include <iostream>
#include "../utils/singleton.h"

using std::cout;

class Scheduler : public Singleton<Scheduler> {

public:

    void start() {
        cout << "Starting Scheduler\n";
    }

    void end() {
        cout << "Ending Scheduler\n";
    }
};

#endif //QUADROBANK_SCHEDULER_H
