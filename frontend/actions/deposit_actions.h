#ifndef QUADROBANK_DEPOSIT_ACTIONS_H
#define QUADROBANK_DEPOSIT_ACTIONS_H

#include <vector>
#include "../../backend/utils/singleton.h"
#include "../../backend/utils/response.h"
#include "../../backend/account/dto/session_token_dto.h"
#include "../../backend/deposit/dto/deposit_dto.h"
#include "../../backend/deposit/dto/deposit_variant_dto.h"
#include "../../backend/deposit/dto/deposit_create_dto.h"

using std::vector;

class DepositActions : public Singleton<DepositActions> {

private:

    friend Singleton;

    DepositActions() = default;

public:

    Response<vector<DepositDto>> get_all_by_user(const SessionTokenDto &session_token_dto) const {
        auto *result = new vector<DepositDto>();
        result->push_back(
                DepositDto{45, 2592000, 1603640493, 1606232493, 0.09, 400}
        );
        return Response<vector<DepositDto>>::success(result);
    }

    Response<vector<DepositVariantDto>> get_possible_variants(const SessionTokenDto &session_token_dto) const {
        auto *result = new vector<DepositVariantDto>();
        result->push_back(
                DepositVariantDto{2592000, 0.09}
        );
        return Response<vector<DepositVariantDto>>::success(result);
    }

    Response<void> create(const DepositCreateDto &deposit_create_dto) const {
        return Response<void>::success();
    }
};

#endif //QUADROBANK_DEPOSIT_ACTIONS_H
