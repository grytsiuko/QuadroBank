#ifndef QUADROBANK_REGULAR_PAYMENT_ACTIONS_H
#define QUADROBANK_REGULAR_PAYMENT_ACTIONS_H

#include <vector>
#include "../../backend/utils/singleton.h"
#include "../../backend/utils/response.h"
#include "../../backend/regular_payment/dto/regular_payment_dto.h"
#include "../../backend/account/dto/session_token_dto.h"
#include "../../backend/regular_payment/dto/regular_payment_create_dto.h"
#include "../../backend/regular_payment/dto/regular_payment_update_dto.h"
#include "../../backend/regular_payment/dto/regular_payment_delete_dto.h"

using std::vector;

class RegularPaymentActions : public Singleton<RegularPaymentActions> {

private:

    friend Singleton;

    RegularPaymentActions() = default;

public:

    Response<vector<RegularPaymentDto>> get_all_by_user(const SessionTokenDto &session_token_dto) const {
        auto *result = new vector<RegularPaymentDto>();
        result->push_back(
                RegularPaymentDto{45, 86400, "2222 2222 2222 2222", 10}
        );
        return Response<vector<RegularPaymentDto>>::success(result);
    }

    Response<void> create(const RegularPaymentCreateDto &regular_payment_create_dto) const {
        return Response<void>::success();
    }

    Response<void> update(const RegularPaymentUpdateDto &regular_payment_update_dto) const {
        return Response<void>::success();
    }

    Response<void> remove(const RegularPaymentDeleteDto &regular_payment_delete_dto) const {
        return Response<void>::success();
    }
};

#endif //QUADROBANK_REGULAR_PAYMENT_ACTIONS_H
