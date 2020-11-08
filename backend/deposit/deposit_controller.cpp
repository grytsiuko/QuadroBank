
#include "deposit_controller.h"

Response<vector<DepositDto>> DepositController::get_all_by_user(const TokenDto &tokenDto) const {
    log("get_all_by_user");
    try{
        vector<DepositDto> deposits =  _deposit_service.get_all_by_user(tokenDto);
        return Response<vector<DepositDto>>::success(deposits);
    } catch (const Exception &exception) {
        return Response<vector<DepositDto>>::error(exception.get_message());
    }
}

Response<vector<DepositVariantDto>> DepositController::get_possible_variants(const TokenDto &token_dto) const {
    log("get_possible_variants");
    try{
        vector<DepositVariantDto> deposit_variants =  _deposit_service.get_possible_variants(token_dto);
        return Response<vector<DepositVariantDto>>::success(deposit_variants);
    } catch (const Exception &exception) {
        return Response<vector<DepositVariantDto>>::error(exception.get_message());
    }
}

Response<void> DepositController::add(const DepositCreateDto &depositCreateDto) const {
    log("add");
    try{
        _deposit_service.add(depositCreateDto);
        return Response<void>::success();
    } catch (const Exception &exception) {
        return Response<void>::error(exception.get_message());
    }
}
