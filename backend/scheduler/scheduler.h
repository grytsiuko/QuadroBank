#ifndef QUADROBANK_SCHEDULER_H
#define QUADROBANK_SCHEDULER_H

#include <iostream>
#include <thread>
#include "../utils/singleton.h"

using std::cout;
using std::thread;

class Scheduler : public Singleton<Scheduler> {

private:

    friend Singleton;

    mutable thread _th;
    mutable volatile bool _looping;

    Scheduler() : _looping(true), _th(thread([this] { loop(); })) {}

    ~Scheduler() override {
        _looping = false;
        _th.join(); // to wait until tasks is done, not to interrupt
    }

    void loop() const {
        while (_looping) {
            cout << "************ I am scheduler ************\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
};

#endif //QUADROBANK_SCHEDULER_H
