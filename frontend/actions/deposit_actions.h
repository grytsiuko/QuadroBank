#ifndef QUADROBANK_DEPOSIT_ACTIONS_H
#define QUADROBANK_DEPOSIT_ACTIONS_H

#include <vector>
#include <backend/deposit/deposit_controller.h>
#include "../../backend/utils/singleton.h"
#include "../../backend/utils/response.h"
#include "../../backend/account/dto/token_dto.h"
#include "../../backend/deposit/dto/deposit_dto.h"
#include "../../backend/deposit/dto/deposit_variant_dto.h"
#include "../../backend/deposit/dto/deposit_create_dto.h"

using std::vector;

class DepositActions : public Singleton<DepositActions> {

private:

    friend Singleton;

    const DepositController &_deposit_controller;

    DepositActions(): _deposit_controller(DepositController::get_instance()) {}

public:

    Response<vector<DepositDto>> get_all_by_user(const TokenDto &token_dto) const {
        return _deposit_controller.get_all_by_user(token_dto);
    }

    Response<vector<DepositVariantDto>> get_possible_variants(const TokenDto &token_dto) const {
        return _deposit_controller.get_possible_variants(token_dto);
    }

    Response<void> create(const DepositCreateDto &deposit_create_dto) const {
        return _deposit_controller.add(deposit_create_dto);
    }
};

#endif //QUADROBANK_DEPOSIT_ACTIONS_H
