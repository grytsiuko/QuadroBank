#include "refillmenu.h"
#include "ui_refillmenu.h"
#include "frontend/menus/utils/info_message/info_message.h"
#include "../utils/update_balance_label/balance_label_util.h"
#include "../utils/amount_converter/amount_convert.h"

RefillMenu::~RefillMenu()
{
    delete ui;
}
void RefillMenu::set_token(const SessionDto &token) {
    TokenInterface::set_token(token);
    update_balance_label();
}

void RefillMenu::update_balance_label() {
    const Response<AccountBalanceDto>& balanceDTO = accountActions.check_balance(TokenDto{currentToken._token});
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        update_label(ui->LabelName, account_balance);
    }
}

void RefillMenu::clear_inputs(){
    ui->amount_input->setText("");
}

void RefillMenu::refill(){
    int amount = convertAmount(ui->amount_input->text());
    if (amount == 0){
        showInfo("Amount cannot be 0");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    }
    else {
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