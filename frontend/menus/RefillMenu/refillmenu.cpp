#include "refillmenu.h"
#include "ui_refillmenu.h"
#include "../utils/info_message.h"

RefillMenu::~RefillMenu()
{
    delete ui;
}
void RefillMenu::set_token(const TokenDto &token) {
    currentToken = token;
    update_balance_label();
}

void RefillMenu::update_balance_label() {
    const Response<AccountBalanceDto>& balanceDTO = accountActions.check_balance(currentToken);
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        QString balanceString;
        if (account_balance._credit_limit > 0)
            balanceString = QString("Your Balance: %1 $ (Cred Limit: %2)").arg(account_balance._balance).arg(account_balance._credit_limit);
        else
            balanceString = QString("Your Balance: %1 $").arg(account_balance._balance);
        ui->LabelName->setText(balanceString);
    }
}

void RefillMenu::refill(){
    int amount = ui->amount_input->text().toInt();
    if (amount < 1) {
        showInfo("Amount should be positive number");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    } else {
        const Response<void>& responseTransfer = accountActions.top_up(
                AccountUpdateDto{currentToken._token, amount});
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