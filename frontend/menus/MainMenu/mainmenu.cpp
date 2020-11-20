#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QDebug>

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::set_token(const SessionDto &token) {
    TokenInterface::set_token(token);
    update_balance_label();
}

void MainMenu::update_balance_label(){
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(TokenDto{currentToken._token});
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        QString balanceString;
        if (account_balance._credit_limit > 0)
            balanceString = QString("Your Balance: %1 $\n(Cred Limit: %2)").arg(1.*account_balance._balance/100).arg(1.*account_balance._credit_limit/100);
        else
            balanceString = QString("Your Balance: %1 $").arg(1.*account_balance._balance/100);
        ui->LabelName->setText(balanceString);
    }
};