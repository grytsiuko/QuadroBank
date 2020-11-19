cmake_minimum_required(VERSION 3.5)
project(QuadroBank)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}Sql REQUIRED)


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

        frontend/menus/UpdatePaymentMenu/updatepaymentmenu.cpp
        frontend/menus/UpdatePaymentMenu/updatepaymentmenu.ui
        frontend/menus/UpdatePaymentMenu/updatepaymentmenu.h

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
        frontend/demo_deposit_scheduler.h
        backend/regular_payment/model/regular_payment.h
        backend/regular_payment/regular_payment_repository_interface.h
        backend/regular_payment/regular_payment_repository_in_memory.cpp
        backend/regular_payment/regular_payment_repository_in_memory.h
        backend/regular_payment/regular_payment_service.cpp
        backend/regular_payment/regular_payment_service.h
        backend/regular_payment/regular_payment_controller.h
        frontend/menus/utils/date_utils/date_util.h
        frontend/menus/utils/date_utils/date_util.cpp
        frontend/demo_regular_payment_scheduler.h

        backend/notification/notification_service.h
        backend/auth/auth_service.h
        backend/account/account_controller.cpp
        backend/account/account_repository_in_memory.cpp
        backend/account/account_service.cpp
        backend/auth/auth_service.cpp
        backend/deposit/deposit_controller.cpp
        backend/regular_payment/regular_payment_controller.cpp
        backend/scheduler/scheduler.cpp
        backend/user/user_repository_in_memory.cpp
        frontend/menus/utils/info_message/info_message.h
        frontend/menus/utils/info_message/info_message.cpp
        backend/regular_payment/dto/regular_payment_get_dto.h

        backend/db/db_service.h
        backend/user/user_repository_db.h
        backend/account/account_repository_db.h
        backend/account/account_repository_db.cpp
        backend/user/user_repository_db.cpp
        backend/regular_payment/regular_payment_repository_db.h
        backend/regular_payment/regular_payment_repository_db.cpp
        backend/deposit/deposit_repository_db.h
        backend/deposit/deposit_repository_db.cpp
        backend/deposit/deposit_variant_repository_db.h
        backend/deposit/deposit_variant_repository_db.cpp
        backend/utils/string_convert.h

        frontend/menus/utils/token_menu_interface/token_menu_interface.h
        frontend/menus/utils/token_menu_interface/token_menu_interface.cpp

        backend/db/specifications/specification.h
        backend/db/specifications/deposits_by_card_number_specification.h
        backend/db/specifications/deposit_variants_all_specification.h
        backend/db/specifications/deposits_before_time_specification.h
        backend/db/specifications/deposits_all_except_this_specification.h
        backend/db/specifications/accounts_debtor_at_time_specification.h
        backend/db/specifications/rps_by_card_number_specification.h
        backend/db/specifications/rps_time_passed_specification.h
        backend/db/specifications/rps_all_except_this_specification.h)


target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Sql)

#set(G3_RELEASE_DIR  "release")
#set(G3_DEBUG_DIR "debug")
#set(QT5_DIR "C:/Qt/5.15.1/mingw81_64")
#if( WIN32 )
#    SET(QT_DLL
#            Qt5Core
#            Qt5Gui
#            Qt5Widgets
#            Qt5OpenGL
#            Qt5Concurrent
#            )
#
#    foreach( _file ${QT_DLL} )
#        list( APPEND DLL_LIBRARIES  "${QT5_DIR}/bin/${_file}.dll" )
#    endforeach( _file ${QT_DLL} )
#
#endif( WIN32 )
#
## I add other DLLs of other project's library by appending to
##DLL_LIBRARIES and DLL_LIBRARIES_D
#
##Handle DLLs under Windows.
#if(WIN32)
#
#    set(DLL_LIBRARIES_PATH "")
#    set(DLL_LIBRARIES_D_PATH "")
#
#    #Process Release libraries.
#    foreach( _file ${DLL_LIBRARIES} )
#
#        # Convert path to CMake path to avoid escaping issues.
#        file(TO_CMAKE_PATH ${_file} _file_cmake_path)
#
#        #check file existance
#        if(NOT EXISTS ${_file_cmake_path})
#            message(FATAL_ERROR "Missing dll file: ${_file_cmake_path}")
#        endif(NOT EXISTS ${_file_cmake_path})
#
#        # Add the DLL to the installation process.
#        install(FILES ${_file_cmake_path}
#                DESTINATION ${G3_RELEASE_DIR}
#                CONFIGURATIONS Release RelWithDebInfo MinSizeRel Release_CMT
#                Release_Net)
#
#        # Extract the folder path of the DLL. It allows to add the folder
#        #        where the
#        # DLLs are stored to the PATH environment of Visual Studio, in
#        #        order to avoid
#        # copying DLL after each builds.
#        if(MSVC)
#            get_filename_component(_dll_folder ${_file} DIRECTORY)
#            list(APPEND DLL_LIBRARIES_PATH ${_dll_folder})
#        endif(MSVC)
#
#    endforeach( _file ${DLL_LIBRARIES} )
#
#    #Process Debug libraries.
#    foreach( _file ${DLL_LIBRARIES_D} )
#
#        # Convert path to CMake path to avoid escaping issues.
#        file(TO_CMAKE_PATH ${_file} _file_cmake_path)
#
#        #check file existance
#        if(NOT EXISTS ${_file_cmake_path})
#            message(FATAL_ERROR "Missing dll file: ${_file_cmake_path}")
#        endif(NOT EXISTS ${_file_cmake_path})
#
#        # Add the DLL to the installation process.
#        install(FILES ${_file_cmake_path}
#                DESTINATION ${G3_DEBUG_DIR}
#                CONFIGURATIONS Debug)
#
#        # Extract the folder path of the DLL. It allows to add the folder
#        #        where the
#        # DLLs are stored to the PATH environment of Visual Studio, in
#        #        order to avoid
#        # copying DLL after each builds.
#        if(MSVC)
#            get_filename_component(_dll_folder ${_file} DIRECTORY)
#            list(APPEND DLL_LIBRARIES_PATH_D ${_dll_folder})
#        endif(MSVC)
#
#    endforeach( _file ${DLL_LIBRARIES_D} )
#
#    if(MSVC)
#        #Remove duplicate entries
#        list(REMOVE_DUPLICATES DLL_LIBRARIES_PATH)
#        list(REMOVE_DUPLICATES DLL_LIBRARIES_PATH_D)
#
#        #Set architecture
#        if(ARCH_X64)
#            set(DLL_LIBRARIES_ARCH "x64")
#        else(ARCH_X64)
#            set(DLL_LIBRARIES_ARCH "Win32")
#        endif(ARCH_X64)
#
#        # The output file goes in the build dir.
#        # @ONLY means only variables of the form @VAR@ will be substituted.
#        # This method need DLL_LIBRARIES_ARCH, DLL_LIBRARIES_PATH and
#        #        DLL_LIBRARIES_PATH_D
#        # variables to be set. DONT FORGET TO RESTART VISUAL STUDIO if DLL
#        #        paths changes, as
#        # vcxproj.user files are loaded only once at Visual Studio startup.
#
#        configure_file(project.vcxproj.user.in
#                ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.vcxproj.user @ONLY)
#    endif(MSVC)
#
#endif(WIN32)



