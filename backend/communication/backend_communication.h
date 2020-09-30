#ifndef QUADROBANK_BACKEND_COMMUNICATION_H
#define QUADROBANK_BACKEND_COMMUNICATION_H

#include <iostream>
#include "../user_service/user_service.h"

using namespace std;

class BackendCommunication {

private:

    UserService user_service;

public:

    BackendCommunication() : user_service(UserService()) {}

    void pong() {
        user_service.test_connection();
        cout << "Successful pong from backend to frontend" << endl;
    }
};

#endif
