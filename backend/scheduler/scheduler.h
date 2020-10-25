#ifndef QUADROBANK_SCHEDULER_H
#define QUADROBANK_SCHEDULER_H

#include <iostream>
#include <thread>
#include "../utils/singleton.h"

using std::cout;
using std::thread;

class Scheduler : public Singleton<Scheduler> {

private:

    void loop() const {
        while (true) {
            cout << "************ I am scheduler ************\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

public:

    void start() const {
        cout << "********** Starting Scheduler **********\n";
        thread([this] {
            loop();
        }).detach();
    }
};

#endif //QUADROBANK_SCHEDULER_H
