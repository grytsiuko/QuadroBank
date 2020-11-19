//
// Created by alouh on 18.11.2020.
//

#ifndef QUADROBANK_TOKEN_MENU_INTERFACE_H
#define QUADROBANK_TOKEN_MENU_INTERFACE_H

#include "backend/account/dto/token_dto.h"

class TokenInterface{
public:
    virtual void set_token(const TokenDto& token);
protected:
    ~TokenInterface()= default;
    TokenDto currentToken;
};

#endif //QUADROBANK_TOKEN_MENU_INTERFACE_H
