#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QDebug>

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::set_token(const TokenDto &token) {
    currentToken = token;
    update_balance_label();
}

void MainMenu::update_balance_label(){
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(currentToken);
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        QString balanceString;
        if (account_balance._credit_limit > 0)
            balanceString = QString("Your Balance: %1 $ (Cred Limit: %2)").arg(account_balance._balance).arg(account_balance._credit_limit);
        else
            balanceString = QString("Your Balance: %1 $").arg(account_balance._balance);
        ui->LabelName->setText(balanceString);
    }
    else {
        std::cout << balanceDTO.get_error() << std::endl;
    }
};