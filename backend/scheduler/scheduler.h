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

    void loop() const {
        while (_looping) {
            log("looping Scheduler");
            check_credits();
            check_deposits();
            check_regular_payments();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    void check_credits() const {
        vector<Account> debtors = _account_service.get_debtors();
        for (const Account &account:debtors) {
            _account_service.punish_debtor(account);
            log("Punished " + account._card_number);
        }
    }

    void check_deposits() const {
        vector<Deposit> finished = _deposit_service.get_to_be_paid();
        for (const Deposit &deposit:finished) {
            _deposit_service.return_finished(deposit);
            log("Returned deposit for " + deposit._account_card_number);
        }
    }

    void check_regular_payments() const{
        vector<RegularPayment> should_be_paid = _regular_payment_service.get_to_be_paid();
        for(RegularPayment& rp : should_be_paid){
            _regular_payment_service.pay(rp);
            log("Regular payment from " + rp._account_card + " to " + rp._target_card);
        }
    };
};

#endif //QUADROBANK_SCHEDULER_H
