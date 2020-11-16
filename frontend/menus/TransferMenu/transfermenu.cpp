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
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        QString balanceString;
        if (account_balance._credit_limit > 0)
            balanceString = QString("Your Balance: %1 $\n(Cred Limit: %2)").arg(1.*account_balance._balance/100).arg(1.*account_balance._credit_limit/100);
        else
            balanceString = QString("Your Balance: %1 $").arg(1.*account_balance._balance/100);
        ui->LabelName->setText(balanceString);
    }
}


void TransferMenu::transfer() {
    bool good;
    double amount = ui->amount_input->text().toDouble(&good);
    if (!good) {
        showInfo("Amount should be positive number");


    }
    else if (amount <= 0.001){
        showInfo("Amount cannot be 0 or less");
        ui->amount_input->setStyleSheet("border: 1px solid red");
        ui->amount_input->setText("");
    }
    else {
        const Response<void> &responseTransfer = accountActions.transfer(
                AccountTransferDto{currentToken._token,
                                   ui->card_number_input->text().toStdString(),
                                   static_cast<int>(amount * 100)});
        if (responseTransfer.is_success()) {
            ui->card_number_input->setText("");
            ui->amount_input->setText("");
            showInfo("Successfully created transfer");
            update_balance_label();
        } else {
            showInfo(QString::fromStdString(responseTransfer.get_error()));
        }
    }

}
