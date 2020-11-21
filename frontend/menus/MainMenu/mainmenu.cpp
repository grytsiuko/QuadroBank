#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "../utils/update_balance_label/balance_label_util.h"
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
        update_label(ui->LabelName, account_balance);
        ui->UserLabel->setText(QString("Current User: %1").arg(QString::fromStdString(currentToken._name)));
    }
};