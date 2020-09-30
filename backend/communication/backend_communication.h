#ifndef QUADROBANK_BACKEND_COMMUNICATION_H
#define QUADROBANK_BACKEND_COMMUNICATION_H

#include <iostream>

using namespace std;

class BackendCommunication {
private:

public:
    void pong() {
        cout << "Successful pong from backend to frontend" << endl;
    }
};

#endif
