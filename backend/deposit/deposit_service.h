#ifndef QUADROBANK_DEPOSIT_SERVICE_H
#define QUADROBANK_DEPOSIT_SERVICE_H


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
#include "deposit_variant_repository_in_memory.h"
#include "deposit_variant_repsitory_interface.h"

class DepositService : public Singleton<DepositService> {

    friend Singleton;

private:
    const DepositRepositoryInterface &_deposit_repository;
    const AccountRepositoryInterface<AccountRepositoryInMemory> &_account_repository;
    const DepositVariantRepositoryInterface &_deposit_variant_repository;
    const TokenService &_token_service;

    DepositService() : _deposit_repository(DepositRepositoryInMemory::get_instance()),
                       _account_repository(AccountRepositoryInMemory::get_instance()),
                       _deposit_variant_repository(DepositVariantRepositoryInMemory::get_instance()),
                       _token_service(TokenService::get_instance()) {}

public:
    vector<DepositDto> get_all_by_user(const SessionDto &sessionDto) const;

    vector<DepositVariantDto> get_possible_variants() const;

    void add(const DepositCreateDto& depositCreateDto) const;

    void remove(int id) const;

    vector<Deposit> get_to_be_paid() const;

};

#endif //QUADROBANK_DEPOSIT_SERVICE_H
