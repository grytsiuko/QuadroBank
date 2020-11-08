#include "transfermenu.h"
#include "ui_transfermenu.h"
#include "../utils/info_message.h"
TransferMenu::~TransferMenu() {
    delete ui;
}

void TransferMenu::set_token(const TokenDto &token) {
    currentToken = token;
    update_balance_label();
}

void TransferMenu::update_balance_label() {
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(currentToken);
    if (balanceDTO.is_success()) {
        const AccountBalanceDto account_balance = balanceDTO.get_response();
        QString balanceString;
        if (account_balance._credit_limit > 0)
            balanceString = QString("Your Balance: %1 $ (Cred Limit: %2)").arg(account_balance._balance).arg(account_balance._credit_limit);
        else
            balanceString = QString("Your Balance: %1 $").arg(account_balance._balance);
        ui->LabelName->setText(balanceString);
    }
}


void TransferMenu::transfer() {
    int amount = ui->amount_input->text().toInt();
    if (amount < 1) {
        showInfo("Amount should be positive number");
        ui->amount_input->setStyleSheet("border: 1px solid red");
        ui->amount_input->setText("");
    } else {
        const Response<void>& responseTransfer = accountActions.transfer(
                AccountTransferDto{currentToken._token, ui->card_number_input->text().toStdString(), amount});
        if (responseTransfer.is_success()){
            ui->card_number_input->setText("");
            ui->amount_input->setText("");
            showInfo("Successfully created transfer");
            update_balance_label();
        }
        else{
            showInfo(QString::fromStdString(responseTransfer.get_error()));
        }
    }

}
