#ifndef QUADROBANK_REGULAR_PAYMENT_CONTROLLER_H
#define QUADROBANK_REGULAR_PAYMENT_CONTROLLER_H

#include "backend/utils/exception.h"
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
    Response<vector<RegularPaymentDto>> get_all_by_user(const TokenDto& token_dto) const{
        log("get_all_by_user");
        try{
            vector<RegularPaymentDto> regular_payment_dtos = _regular_payment_service.get_all_by_user(token_dto);
            return Response<vector<RegularPaymentDto>>::success(regular_payment_dtos);
        } catch (const Exception &exception) {
            return Response<vector<RegularPaymentDto>>::error(exception.get_message());
        }
    }

    Response<void> add(const RegularPaymentCreateDto& regular_payment_create_dto) const{
        log("add");
        try{
            _regular_payment_service.add(regular_payment_create_dto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(exception.get_message());
        }
    }

    Response<void> update(const RegularPaymentUpdateDto& regular_payment_update_dto) const{
        log("update");
        try{
            _regular_payment_service.update(regular_payment_update_dto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(exception.get_message());
        }
    }

    Response<void> remove(const RegularPaymentDeleteDto& regular_payment_delete_dto) const{
        log("update");
        try{
            _regular_payment_service.remove(regular_payment_delete_dto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(exception.get_message());
        }
    }

};

#endif //QUADROBANK_REGULAR_PAYMENT_CONTROLLER_H
