#ifndef QUADROBANK_DEMO_REGULAR_PAYMENT_SCHEDULER_H
#define QUADROBANK_DEMO_REGULAR_PAYMENT_SCHEDULER_H


#include <backend/scheduler/scheduler.h>
#include <frontend/actions/account_actions.h>
#include <frontend/actions/regular_payment_actions.h>
#include <backend/utils/time_intervals.h>
#include <cassert>

using std::endl;

void demo_show_balance(const string& card, const string& pin){
    const AccountActions &account_actions = AccountActions::get_instance();
    Response<SessionDto> authorize_response = account_actions.authorize(
            AccountAuthorizeDto{card, pin});

    assert(authorize_response.is_success());

    TokenDto account_token_dto = TokenDto{authorize_response.get_response()._token};
    Response<AccountBalanceDto> account_balance = account_actions.check_balance(account_token_dto);

    assert(account_balance.is_success());
    cout << "Card: " << card << " | balance: " << account_balance.get_response()._balance << endl;
}

void demo_show_payments(const string& card, const string& pin){
    const AccountActions &account_actions = AccountActions::get_instance();
    const RegularPaymentActions& payment_actions = RegularPaymentActions::get_instance();

    Response<SessionDto> authorize_response = account_actions.authorize(
            AccountAuthorizeDto{card, pin});

    assert(authorize_response.is_success());


    Response<vector<RegularPaymentDto>> response = payment_actions.get_all_by_user(
            TokenDto{authorize_response.get_response()._token});

    assert(response.is_success());

    const vector<RegularPaymentDto>& payments = response.get_response();
    cout << "Regular payments for: " << card << endl;
    for(const RegularPaymentDto& rp : payments){
        cout << "target card: " << rp._target_card << " | period: " << rp._period_sec << "sec | sum: " << rp._sum << endl;
    }
}

void demo_regular_payment_scheduler() {


    const AccountActions &account_actions = AccountActions::get_instance();
    const RegularPaymentActions& payment_actions = RegularPaymentActions::get_instance();

    const string from_card = "1111 1111 1111 1111";
    const string from_pin = "1111";

    const string to_card = "3333 3333 3333 3333";
    const string to_pin = "3333";

    Response<SessionDto> from_authorize_response = account_actions.authorize(
            AccountAuthorizeDto{from_card, from_pin});

    assert(from_authorize_response.is_success());

    demo_show_balance(from_card, from_pin);
    demo_show_balance(to_card, to_pin);

    time_t current_time = time(nullptr);

    Response<void> createResponse = payment_actions.create(RegularPaymentCreateDto{
            from_authorize_response.get_response()._token,
        current_time + 1*TimeIntervals::SECOND,
        3*TimeIntervals::SECOND,
            to_card,
            10
        });

    assert(createResponse.is_success());

    demo_show_payments(from_card, from_pin);

    Scheduler::get_instance();

    //sleep
    std::this_thread::sleep_for(std::chrono::milliseconds(8000));

    demo_show_balance(from_card, from_pin);
    demo_show_balance(to_card, to_pin);
}


#endif //QUADROBANK_DEMO_REGULAR_PAYMENT_SCHEDULER_H
