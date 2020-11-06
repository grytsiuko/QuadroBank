#include "refillmenu.h"
#include "ui_refillmenu.h"

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
        QString balanceString = QString::number(account_balance._balance);
        ui->LabelName->setText(balanceString);
    }
}

void RefillMenu::refill(){
    int amount = ui->amount_input->text().toInt();
    if (amount < 1) {
        ui->amount_input->setStyleSheet("border: 1px solid red");
    } else {
        const Response<void>& responseTransfer = accountActions.top_up(
                AccountUpdateDto{currentToken._token, amount});
        if (responseTransfer.is_success()){
            update_balance_label();
        }
    }
    ui->amount_input->setText("");
}