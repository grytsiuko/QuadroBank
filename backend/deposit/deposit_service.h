#ifndef QUADROBANK_DEPOSIT_SERVICE_H
#define QUADROBANK_DEPOSIT_SERVICE_H


#include <cmath>
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
    vector<DepositDto> get_all_by_user(const TokenDto &tokenDto) const;

    vector<DepositVariantDto> get_possible_variants(const TokenDto &token_dto) const;

    void add(const DepositCreateDto& depositCreateDto) const;

    void remove(int id) const;

    vector<Deposit> get_to_be_paid() const;

    vector<Deposit> get_finished() const {
        function<bool(const Deposit&)> finished_filter = [](auto &a) {
            return a._end_date < time(nullptr);
        };
        return _deposit_repository.get_list(Specification<Deposit>(finished_filter));
    }

    void return_finished(const Deposit &deposit) const {
        Optional<Account> account_optional = _account_repository.get_by_card_number(deposit._account_card_number);

        if (account_optional.is_empty()) {
            throw Exception("Internal error");
        }
        Account account = *account_optional.get();

        account._balance += floor(deposit._sum * (1 + deposit._percentage));
        _account_repository.update(account);
        _deposit_repository.remove(deposit._id);
    }


};

#endif //QUADROBANK_DEPOSIT_SERVICE_H
