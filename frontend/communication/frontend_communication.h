#ifndef QUADROBANK_FRONTEND_COMMUNICATION_H
#define QUADROBANK_FRONTEND_COMMUNICATION_H

#include <iostream>
#include "../../backend/communication/backend_communication.h"

using namespace std;

class FrontendCommunication {
private:
    BackendCommunication backendCommunication;

public:
    FrontendCommunication() : backendCommunication(BackendCommunication()) {}

    void ping() {
        cout << "Pinging backend from frontend" << endl;
        backendCommunication.pong();
    }
};

#endif
