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
    Response<vector<DepositDto>> get_all_by_user(const TokenDto& tokenDto) const;

    Response<vector<DepositVariantDto>> get_possible_variants(const TokenDto &token_dto) const;

    Response<void> add(const DepositCreateDto& depositCreateDto) const;
};

#endif //QUADROBANK_DEPOSIT_CONTROLLER_H
