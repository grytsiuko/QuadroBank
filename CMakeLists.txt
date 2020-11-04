cmake_minimum_required(VERSION 3.5)
project(QuadroBank)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


add_executable(QuadroBank
        frontend/main.cpp
        frontend/actions/account_actions.h
        backend/account/dto/token_dto.h
        backend/account/dto/account_authorize_dto.h
        backend/account/account_controller.h
        frontend/actions/deposit_actions.h
        backend/deposit/dto/deposit_dto.h
        backend/deposit/dto/deposit_variant_dto.h
        backend/deposit/dto/deposit_create_dto.h
        frontend/actions/regular_payment_actions.h
        backend/regular_payment/dto/regular_payment_create_dto.h
        backend/regular_payment/dto/regular_payment_update_dto.h
        backend/regular_payment/dto/regular_payment_delete_dto.h
        backend/regular_payment/dto/regular_payment_dto.h
        backend/scheduler/scheduler.h
        backend/account/account_service.h
        backend/account/account_repository_interface.h
        backend/utils/optional.h
        backend/account/model/account.h
        backend/account/account_repository_in_memory.h
        backend/utils/response.h
        backend/utils/non_copying.h
        backend/utils/singleton.h
        backend/account/dto/account_balance_dto.h
        backend/token/token_service.h
        backend/account/dto/account_update_dto.h
        backend/account/dto/account_transfer_dto.h
        backend/utils/exception.h
        backend/user/user_repository_interface.h
        backend/user/model/user.h
        backend/user/user_repository_in_memory.h
        backend/account/dto/session_dto.h
        backend/log/log_service.h
        frontend/demo_account.h
        frontend/demo_credit_scheduler.h
        backend/db/specification.h 
        backend/deposit/deposit_controller.h 
        backend/deposit/deposit_repository_in_memory.h 
        backend/deposit/deposit_repository_interface.h 
        backend/deposit/model/deposit.h 
        backend/deposit/deposit_service.h 
        backend/deposit/deposit_repository_in_memory.cpp 
        backend/deposit/deposit_service.cpp   

        frontend/mainwindow.cpp
        frontend/mainwindow.h
        frontend/mainwindow.ui

        frontend/menus/utils/object_ui.h
        backend/utils/singleton.h
        backend/utils/non_copying.h

        frontend/menus/MainMenu/mainmenu.cpp
        frontend/menus/MainMenu/mainmenu.h
        frontend/menus/MainMenu/mainmenu.ui

        frontend/menus/NewDepositMenu/newdepositmenu.cpp
        frontend/menus/NewDepositMenu/newdepositmenu.h
        frontend/menus/NewDepositMenu/newdepositmenu.ui

        frontend/menus/TransferMenu/transfermenu.cpp
        frontend/menus/TransferMenu/transfermenu.h
        frontend/menus/TransferMenu/transfermenu.ui

        frontend/menus/PaymentsMenu/paymentsmenu.cpp
        frontend/menus/PaymentsMenu/paymentsmenu.ui
        frontend/menus/PaymentsMenu/paymentsmenu.h

        frontend/menus/NewPaymentMenu/newpaymentmenu.cpp
        frontend/menus/NewPaymentMenu/newpaymentmenu.ui
        frontend/menus/NewPaymentMenu/newpaymentmenu.h

        frontend/menus/WithdrawMenu/withdrawmenu.cpp
        frontend/menus/WithdrawMenu/withdrawmenu.h
        frontend/menus/WithdrawMenu/withdrawmenu.ui

        frontend/menus/RefillMenu/refillmenu.cpp
        frontend/menus/RefillMenu/refillmenu.h
        frontend/menus/RefillMenu/refillmenu.ui

        frontend/menus/DepositsMenu/depositsmenu.cpp
        frontend/menus/DepositsMenu/depositsmenu.h
        frontend/menus/DepositsMenu/depositsmenu.ui

        frontend/menus/LoginMenu/loginmenu.cpp
        frontend/menus/LoginMenu/loginmenu.h
        frontend/menus/LoginMenu/loginmenu.ui 
        backend/deposit/model/deposit_variant.h 
        backend/deposit/deposit_variant_repsitory_interface.h 
        backend/deposit/deposit_variant_repository_in_memory.h 
        backend/deposit/deposit_variant_repository_in_memory.cpp
        backend/utils/time_intervals.h
        frontend/demo_deposit_scheduler.h backend/regular_payment/model/regular_payment.h backend/regular_payment/regular_payment_repository_interface.h backend/regular_payment/regular_payment_repository_in_memory.cpp backend/regular_payment/regular_payment_repository_in_memory.h backend/regular_payment/regular_payment_service.cpp backend/regular_payment/regular_payment_service.h backend/regular_payment/regular_payment_controller.h)

target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets)
