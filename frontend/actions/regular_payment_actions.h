#ifndef QUADROBANK_REGULAR_PAYMENT_ACTIONS_H
#define QUADROBANK_REGULAR_PAYMENT_ACTIONS_H

#include <vector>
#include <backend/regular_payment/regular_payment_controller.h>
#include "../../backend/utils/singleton.h"
#include "../../backend/utils/response.h"
#include "../../backend/regular_payment/dto/regular_payment_dto.h"
#include "../../backend/account/dto/token_dto.h"
#include "../../backend/regular_payment/dto/regular_payment_create_dto.h"
#include "../../backend/regular_payment/dto/regular_payment_update_dto.h"
#include "../../backend/regular_payment/dto/regular_payment_delete_dto.h"

using std::vector;

class RegularPaymentActions : public Singleton<RegularPaymentActions> {

private:

    friend Singleton;

    const RegularPaymentController& _regular_payment_controller;

    RegularPaymentActions(): _regular_payment_controller(RegularPaymentController::get_instance()) {};

public:

    Response<vector<RegularPaymentDto>> get_all_by_user(const TokenDto &token_dto) const {
        return _regular_payment_controller.get_all_by_user(token_dto);
    }

    Response<void> create(const RegularPaymentCreateDto &regular_payment_create_dto) const {
        return _regular_payment_controller.add(regular_payment_create_dto);
    }

    Response<void> update(const RegularPaymentUpdateDto &regular_payment_update_dto) const {
        return _regular_payment_controller.update(regular_payment_update_dto);
    }

    Response<void> remove(const RegularPaymentDeleteDto &regular_payment_delete_dto) const {
        return _regular_payment_controller.remove(regular_payment_delete_dto);
    }
};

#endif //QUADROBANK_REGULAR_PAYMENT_ACTIONS_H
