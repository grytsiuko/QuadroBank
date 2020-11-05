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
            return Response<vector<DepositDto>>::success(deposits);
        } catch (const Exception &exception) {
            return Response<vector<DepositDto>>::error(exception.get_message());
        }
    }

    Response<vector<DepositVariantDto>> get_possible_variants(const TokenDto &token_dto) const{
        log("get_possible_variants");
        try{
            vector<DepositVariantDto> deposit_variants =  _deposit_service.get_possible_variants(token_dto);
            return Response<vector<DepositVariantDto>>::success(deposit_variants);
        } catch (const Exception &exception) {
            return Response<vector<DepositVariantDto>>::error(exception.get_message());
        }
    }

    Response<void> add(const DepositCreateDto& depositCreateDto) const{
        log("add");
        try{
            _deposit_service.add(depositCreateDto);
            return Response<void>::success();
        } catch (const Exception &exception) {
            return Response<void>::error(exception.get_message());
        }
    }
};

#endif //QUADROBANK_DEPOSIT_CONTROLLER_H
