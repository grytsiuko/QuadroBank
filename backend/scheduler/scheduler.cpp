
#include "scheduler.h"

void Scheduler::loop() const {
    while (_looping) {
        log("looping Scheduler");
        check_credits();
        check_deposits();
        check_regular_payments();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void Scheduler::check_credits() const {
    vector<Account> debtors = _account_service.get_debtors();
    for (const Account &account:debtors) {
        _account_service.punish_debtor(account);
        log("Punished " + account._card_number);
    }
}

void Scheduler::check_deposits() const {
    vector<Deposit> finished = _deposit_service.get_to_be_paid();
    for (const Deposit &deposit:finished) {
        _deposit_service.return_finished(deposit);
        log("Returned deposit for " + deposit._account_card_number);
    }
}

void Scheduler::check_regular_payments() const {
    vector<RegularPayment> should_be_paid = _regular_payment_service.get_to_be_paid();
    for(RegularPayment& rp : should_be_paid){
        _regular_payment_service.pay(rp);
        log("Regular payment from " + rp._account_card + " to " + rp._target_card);
    }
}
