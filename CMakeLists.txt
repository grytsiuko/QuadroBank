cmake_minimum_required(VERSION 3.14)
project(QuadroBank)

set(CMAKE_CXX_STANDARD 14)

add_executable(QuadroBank
        frontend/main.cpp
        frontend/actions/account_actions.h
        backend/account/dto/session_token_dto.h
        backend/account/dto/account_authorize_dto.h
        backend/account/account_controller.h
        backend/account/account_service.h backend/account/account_repository_interface.h backend/utils/optional.h backend/account/model/account.h backend/account/account_repository_in_memory.h backend/utils/response.h backend/utils/non_copying.h backend/utils/singleton.h backend/account/dto/account_balance_dto.h backend/token/token_service.h backend/account/dto/account_update_dto.h backend/account/dto/account_transfer_dto.h backend/utils/exception.h frontend/actions/deposit_actions.h backend/deposit/dto/deposit_dto.h backend/deposit/dto/deposit_variant_dto.h backend/deposit/dto/deposit_create_dto.h frontend/actions/regular_payment_actions.h backend/regular_payment/dto/regular_payment_create_dto.h backend/regular_payment/dto/regular_payment_update_dto.h backend/regular_payment/dto/regular_payment_delete_dto.h backend/regular_payment/dto/regular_payment_dto.h)