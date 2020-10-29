#ifndef QUADROBANK_DEPOSIT_CONTROLLER_H
#define QUADROBANK_DEPOSIT_CONTROLLER_H

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
    Response<vector<DepositDto>> get_all_by_user(const SessionDto& sessionDto) const{
        log("get_all_by_user");
        try{
            vector<DepositDto> deposits =  _deposit_service.get_all_by_user(sessionDto);
            return Response<vector<DepositDto>>::success(new vector<DepositDto>(std::move(deposits)));
        } catch (const Exception &exception) {
            return Response<vector<DepositDto>>::error(new string(exception.get_message()));
        }
    }

    vector<DepositVariantDto> get_possible_variants() const{
        log("get_possible_variants");
        return _deposit_service.get_possible_variants();
    }

    void add(const DepositCreateDto& depositCreateDto){
        log("add");
        _deposit_service.add(depositCreateDto);
    }
};

#endif //QUADROBANK_DEPOSIT_CONTROLLER_H
