#ifndef QUADROBANK_DEPOSIT_CONTROLLER_H
#define QUADROBANK_DEPOSIT_CONTROLLER_H

#include "../account/dto/token_dto.h"
#include "../utils/singleton.h"
#include "deposit_service.h"
#include "../log/log_service.h"
#include "../utils/response.h"

class DepositController : public Singleton<DepositController> {

    friend Singleton;

private:
    const DepositService &_deposit_service;
    const LogService &_log_service;

    DepositController() :
            _deposit_service(DepositService::get_instance()),
            _log_service(LogService::get_instance()) {}

    void log(const string &text) const {
        _log_service.log("DepositController", text);
    }

public:
    Response<vector<DepositDto>> get_all_by_user(const TokenDto& tokenDto) const{
        log("get_all_by_user");
        try{
            vector<DepositDto> deposits =  _deposit_service.get_all_by_user(tokenDto);
            return Response<vector<DepositDto>>::success(new vector<DepositDto>(std::move(deposits)));
        } catch (const Exception &exception) {
            return Response<vector<DepositDto>>::error(new string(exception.get_message()));
        }
    }

    Response<vector<DepositVariantDto>> get_possible_variants() const{
        log("get_possible_variants");
        try{
            vector<DepositVariantDto> deposit_variants =  _deposit_service.get_possible_variants();
            return Response<vector<DepositVariantDto>>::success(new vector<DepositVariantDto>(std::move(deposit_variants)));
        } catch (const Exception &exception) {
            return Response<vector<DepositVariantDto>>::error(new string(exception.get_message()));
        }
    }

    Response<void> add(const DepositCreateDto& depositCreateDto){
        log("add");
        try{
            _deposit_service.add(depositCreateDto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(new string(exception.get_message()));
        }
    }
};

#endif //QUADROBANK_DEPOSIT_CONTROLLER_H
