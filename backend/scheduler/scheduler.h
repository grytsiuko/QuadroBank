#ifndef QUADROBANK_SCHEDULER_H
#define QUADROBANK_SCHEDULER_H

#include <iostream>
#include <thread>
#include "../utils/singleton.h"
#include "../log/log_service.h"
#include "../account/account_service.h"

using std::cout;
using std::thread;

class Scheduler : public Singleton<Scheduler> {

private:

    friend Singleton;

    mutable thread _th;
    mutable volatile bool _looping;
    const LogService &_log_service;
    const AccountService &_account_service;

    Scheduler() :
            _looping(true),
            _th(thread([this] { loop(); })),
            _log_service(LogService::get_instance()),
            _account_service(AccountService::get_instance()) {}

    ~Scheduler() override {
        _looping = false;
        _th.join(); // to wait until tasks is done, not to interrupt
    }

    void log(const string &text) const {
        _log_service.log("Scheduler        ", text);
    }

    void loop() const {
        while (_looping) {
            log("looping Scheduler");
            check_credits();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    void check_credits() const {
        vector<Account> debtors = _account_service.get_debtors();
    }
};

#endif //QUADROBANK_SCHEDULER_H
