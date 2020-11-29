//
// Created by alouh on 18.11.2020.
//

#ifndef QUADROBANK_TOKEN_MENU_INTERFACE_H
#define QUADROBANK_TOKEN_MENU_INTERFACE_H

#include "backend/account/dto/session_dto.h"

class TokenInterface{
public:
    virtual void set_token(const SessionDto& token);
protected:
    ~TokenInterface()= default;
    SessionDto currentToken;
};

#endif //QUADROBANK_TOKEN_MENU_INTERFACE_H
