#include "refillmenu.h"
#include "ui_refillmenu.h"
#include "frontend/menus/utils/info_message/info_message.h"

RefillMenu::~RefillMenu()
{
    delete ui;
}
void RefillMenu::set_token(const TokenDto &token) {
    TokenInterface::set_token(token);
    update_balance_label();
}

void RefillMenu::update_balance_label() {
    const Response<AccountBalanceDto>& balanceDTO = accountActions.check_balance(currentToken);
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        QString balanceString;
        if (account_balance._credit_limit > 0)
            balanceString = QString("Your Balance: %1 $\n(Cred Limit: %2)").arg(1.*account_balance._balance/100).arg(1.*account_balance._credit_limit/100);
        else
            balanceString = QString("Your Balance: %1 $").arg(1.*account_balance._balance/100);
        ui->LabelName->setText(balanceString);
    }
}

void RefillMenu::refill(){
    bool good;
    double amount = ui->amount_input->text().toDouble(&good);
    if (!good) {
        showInfo("Amount should not be empty");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    }
    else if (amount <= 0.001){
        showInfo("Amount cannot be 0");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    }
    else {
        const Response<void>& responseTransfer = accountActions.top_up(
                AccountUpdateDto{currentToken._token, static_cast<int>(amount*100)});
        if (responseTransfer.is_success()){
            showInfo("Successfully refilled");
            update_balance_label();
        }
        else{
            showInfo(QString::fromStdString(responseTransfer.get_error()));
        }
    }
    ui->amount_input->setText("");
}