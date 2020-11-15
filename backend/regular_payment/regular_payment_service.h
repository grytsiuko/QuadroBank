#ifndef QUADROBANK_REGULAR_PAYMENT_SERVICE_H
#define QUADROBANK_REGULAR_PAYMENT_SERVICE_H

#include <vector>
#include <backend/account/account_repository_interface.h>
#include <backend/account/account_repository_in_memory.h>
#include <backend/token/token_service.h>
#include <backend/notification/notification_service.h>
#include <backend/auth/auth_service.h>
#include <backend/regular_payment/dto/regular_payment_get_dto.h>
#include "regular_payment_repository_in_memory.h"
#include "backend/regular_payment/dto/regular_payment_delete_dto.h"
#include "backend/regular_payment/dto/regular_payment_create_dto.h"
#include "backend/regular_payment/dto/regular_payment_update_dto.h"
#include "backend/regular_payment/dto/regular_payment_dto.h"
#include "backend/account/dto/token_dto.h"
#include "backend/regular_payment/model/regular_payment.h"
#include "backend/utils/singleton.h"
#include "regular_payment_repository_interface.h"

using std::vector;

class RegularPaymentService : public Singleton<RegularPaymentService> {

    friend Singleton;

private:
    const RegularPaymentRepositoryInterface &_regular_payment_repository;
    const AccountRepositoryInterface &_account_repository;
    const TokenService &_token_service;
    const NotificationService &_notification_service;
    const AuthService &_auth_service;

    RegularPaymentService() : _regular_payment_repository(RegularPaymentRepositoryInMemory::get_instance()),
                              _account_repository(AccountRepositoryDb::get_instance()),
                              _token_service(TokenService::get_instance()),
                              _notification_service(NotificationService::get_instance()),
                              _auth_service(AuthService::get_instance()) {}

public:

    RegularPaymentDto get_by_id(const RegularPaymentGetDto& get_dto) const;

    vector<RegularPaymentDto> get_all_by_user(const TokenDto &token_dto) const;

    void add(const RegularPaymentCreateDto& regular_payment_create_dto) const;

    void update(const RegularPaymentUpdateDto& regular_payment_update_dto) const;

    void remove(const RegularPaymentDeleteDto& regular_payment_delete_dto) const;

    vector<RegularPayment> get_to_be_paid() const;

    void pay(RegularPayment regular_payment) const;

};


#endif //QUADROBANK_REGULAR_PAYMENT_SERVICE_H
