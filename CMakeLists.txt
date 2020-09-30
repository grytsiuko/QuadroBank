cmake_minimum_required(VERSION 3.14)
project(QuadroBank)

set(CMAKE_CXX_STANDARD 14)

add_executable(QuadroBank frontend/main.cpp frontend/communication/frontend_communication.h backend/communication/backend_communication.h)