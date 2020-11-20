//
// Created by alouh on 18.11.2020.
//
#include "token_menu_interface.h"

void TokenInterface::set_token(const SessionDto& token){
    if (currentToken._token != token._token)
        currentToken = token;
}