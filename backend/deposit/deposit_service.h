#ifndef QUADROBANK_DEPOSIT_SERVICE_H
#define QUADROBANK_DEPOSIT_SERVICE_H


#include <cmath>
#include <backend/auth/auth_service.h>
#include <backend/notification/notification_service.h>
#include "backend/account/dto/token_dto.h"
#include "deposit_repository_interface.h"
#include "deposit_repository_in_memory.h"
#include "../token/token_service.h"
#include "../account/dto/session_dto.h"
#include "dto/deposit_dto.h"
#include "../user/user_repository_in_memory.h"
#include "../account/account_repository_in_memory.h"
#include "../utils/exception.h"
#include "dto/deposit_create_dto.h"
#include "dto/deposit_variant_dto.h"
#include "deposit_variant_repsitory_interface.h"
#include "deposit_variant_repository_db.h"

class DepositService : public Singleton<DepositService> {

    friend Singleton;

private:
    const DepositRepositoryInterface &_deposit_repository;
    const AccountRepositoryInterface &_account_repository;
    const DepositVariantRepositoryInterface &_deposit_variant_repository;
    const TokenService &_token_service;
    const NotificationService &_notification_service;
    const AuthService &_auth_service;

    DepositService() : _deposit_repository(DepositRepositoryInMemory::get_instance()),
                       _account_repository(AccountRepositoryDb::get_instance()),
                       _deposit_variant_repository(DepositVariantRepositoryDb::get_instance()),
                       _token_service(TokenService::get_instance()),
                       _notification_service(NotificationService::get_instance()),
                       _auth_service(AuthService::get_instance()){}

public:
    vector<DepositDto> get_all_by_user(const TokenDto &token_dto) const;

    vector<DepositVariantDto> get_possible_variants(const TokenDto &token_dto) const;

    void add(const DepositCreateDto& deposit_create_dto) const;

    vector<Deposit> get_to_be_paid() const;

    void return_finished(const Deposit &deposit) const;

};

#endif //QUADROBANK_DEPOSIT_SERVICE_H
