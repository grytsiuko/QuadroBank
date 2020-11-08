#ifndef QUADROBANK_SCHEDULER_H
#define QUADROBANK_SCHEDULER_H

#include <iostream>
#include <thread>
#include <backend/deposit/model/deposit.h>
#include <backend/deposit/deposit_service.h>
#include <backend/regular_payment/regular_payment_service.h>
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
    const DepositService &_deposit_service;
    const RegularPaymentService& _regular_payment_service;

    Scheduler() :
            _looping(true),
            _th(thread([this] { loop(); })),
            _log_service(LogService::get_instance()),
            _account_service(AccountService::get_instance()),
            _deposit_service(DepositService::get_instance()),
            _regular_payment_service(RegularPaymentService::get_instance()){}

    ~Scheduler() override {
        _looping = false;
        _th.join(); // to wait until tasks is done, not to interrupt
    }

    void log(const string &text) const {
        _log_service.log("Scheduler        ", text);
    }

    void loop() const;

    void check_credits() const;

    void check_deposits() const;

    void check_regular_payments() const;
};

#endif //QUADROBANK_SCHEDULER_H
