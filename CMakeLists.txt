cmake_minimum_required(VERSION 3.14)
project(QuadroBank)

set(CMAKE_CXX_STANDARD 14)

add_executable(QuadroBank
        frontend/main.cpp
        frontend/communication/frontend_communication.h
        backend/communication/backend_communication.h
        backend/user_service/user_service.h
        backend/user_service/user_repository.h
        frontend/actions/account_actions.h
        backend/account/dto/session_token_dto.h
        backend/account/dto/account_authorize_dto.h
        backend/account/account_controller.h
        )