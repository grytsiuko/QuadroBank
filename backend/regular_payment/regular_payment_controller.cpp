
#include "regular_payment_controller.h"

Response<vector<RegularPaymentDto>> RegularPaymentController::get_all_by_user(const TokenDto &token_dto) const {
    log("get_all_by_user");
    try{
        vector<RegularPaymentDto> regular_payment_dtos = _regular_payment_service.get_all_by_user(token_dto);
        return Response<vector<RegularPaymentDto>>::success(regular_payment_dtos);
    } catch (const Exception &exception) {
        return Response<vector<RegularPaymentDto>>::error(exception.get_message());
    }
}

Response<void> RegularPaymentController::add(const RegularPaymentCreateDto &regular_payment_create_dto) const {
    log("add");
    try{
        _regular_payment_service.add(regular_payment_create_dto);
        return Response<void>::success();
    } catch (const Exception &exception) {
        return Response<void>::error(exception.get_message());
    }
}

Response<void> RegularPaymentController::update(const RegularPaymentUpdateDto &regular_payment_update_dto) const {
    log("update");
    try{
        _regular_payment_service.update(regular_payment_update_dto);
        return Response<void>::success();
    } catch (const Exception &exception) {
        return Response<void>::error(exception.get_message());
    }
}

Response<void> RegularPaymentController::remove(const RegularPaymentDeleteDto &regular_payment_delete_dto) const {
    log("remove");
    try{
        _regular_payment_service.remove(regular_payment_delete_dto);
        return Response<void>::success();
    } catch (const Exception &exception) {
        return Response<void>::error(exception.get_message());
    }
}
