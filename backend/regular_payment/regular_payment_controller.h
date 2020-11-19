#ifndef QUADROBANK_REGULAR_PAYMENT_CONTROLLER_H
#define QUADROBANK_REGULAR_PAYMENT_CONTROLLER_H

#include "backend/utils/exceptions/exception.h"
#include "regular_payment_service.h"
#include "backend/log/log_service.h"
#include "backend/utils/response.h"

class RegularPaymentController : public Singleton<RegularPaymentController> {

    friend Singleton;

private:
    const RegularPaymentService &_regular_payment_service;
    const LogService &_log_service;

    RegularPaymentController() :
            _regular_payment_service(RegularPaymentService::get_instance()),
            _log_service(LogService::get_instance()) {}

    void log(const string &text) const {
        _log_service.log("RegularPaymentController", text);
    }

public:
    Response<RegularPaymentDto> get_by_id(const RegularPaymentGetDto& get_dto) const;

    Response<vector<RegularPaymentDto>> get_all_by_user(const TokenDto& token_dto) const;

    Response<void> add(const RegularPaymentCreateDto& regular_payment_create_dto) const;

    Response<void> update(const RegularPaymentUpdateDto& regular_payment_update_dto) const;

    Response<void> remove(const RegularPaymentDeleteDto& regular_payment_delete_dto) const;

};

#endif //QUADROBANK_REGULAR_PAYMENT_CONTROLLER_H
