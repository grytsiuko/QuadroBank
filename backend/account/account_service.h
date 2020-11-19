#ifndef QUADROBANK_ACCOUNT_SERVICE_H
#define QUADROBANK_ACCOUNT_SERVICE_H

#include <cmath>
#include <ctime>
#include <map>
#include <backend/notification/notification_service.h>
#include <backend/auth/auth_service.h>
#include <backend/user/user_repository_db.h>
#include "dto/account_authorize_dto.h"
#include "dto/token_dto.h"
#include "account_repository_interface.h"
#include "account_repository_in_memory.h"
#include "../utils/response.h"
#include "../utils/singleton.h"
#include "dto/account_balance_dto.h"
#include "../token/token_service.h"
#include "dto/account_update_dto.h"
#include "dto/account_transfer_dto.h"
#include "../utils/exception.h"
#include "../user/user_repository_interface.h"
#include "../user/user_repository_in_memory.h"
#include "dto/session_dto.h"
#include "account_repository_db.h"

using std::map;

class AccountService : public Singleton<AccountService> {

    friend Singleton;

private:

    const static int CREDIT_SECONDS = 10;
    constexpr const static double CREDIT_COEFFICIENT = 1.2;

    const int MAX_INCORRECT_PINS = 3;
    mutable map<string, int> _incorrect_pins;

    const AccountRepositoryInterface &_account_repository;
    const UserRepositoryInterface &_user_repository;
    const TokenService &_token_service;
    const NotificationService &_notification_service;
    const AuthService &_auth_service;



    AccountService() :
            _account_repository(AccountRepositoryDb::get_instance()),
            _user_repository(UserRepositoryDb::get_instance()),
            _token_service(TokenService::get_instance()),
            _notification_service(NotificationService::get_instance()),
            _auth_service(AuthService::get_instance()){}

public:

    SessionDto authorize(const AccountAuthorizeDto &account_authorize_dto) const;

    AccountBalanceDto check_balance(const TokenDto &token_dto) const;

    void top_up(const AccountUpdateDto &account_update_dto) const;

    void withdraw(const AccountUpdateDto &account_update_dto) const;

    void transfer(const AccountTransferDto &account_transfer_dto) const;

    vector<Account> get_debtors() const;

    void punish_debtor(Account account) const;

    void update(Account account) const;

private:

    void _assert_positive_sum(int sum) const;

    void _assert_correct_balance(const Account &account) const;

    void _update_credit_start(Account &account) const;
};

#endif
