#include "transfermenu.h"
#include "ui_transfermenu.h"
#include "frontend/menus/utils/info_message/info_message.h"
#include "../utils/update_balance_label/balance_label_util.h"
#include "../utils/amount_converter/amount_convert.h"
TransferMenu::~TransferMenu() {
    delete ui;
}

void TransferMenu::set_token(const SessionDto &token) {
    TokenInterface::set_token(token);
    update_balance_label();
}
void TransferMenu::clear_inputs(){
    ui->card_number_input->setText("");
    ui->amount_input->setText("");
}

void TransferMenu::update_balance_label() {
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(TokenDto{currentToken._token});
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        update_label(ui->LabelName, account_balance);
    }
}


void TransferMenu::transfer() {
    int amount = convertAmount(ui->amount_input->text());
    if (amount == 0){
        showInfo("Amount cannot be 0");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    }
    else {
        const Response<void> responseTransfer = accountActions.transfer(
                AccountTransferDto{currentToken._token,
                                   ui->card_number_input->text().toStdString(),
                                   amount});
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
