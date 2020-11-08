#include "withdrawmenu.h"
#include "ui_withdrawmenu.h"
#include "../utils/info_message.h"

WithdrawMenu::~WithdrawMenu()
{
    delete ui;
}

void WithdrawMenu::set_token(const TokenDto& token){
    currentToken = token;
    update_balance_label();
}

void WithdrawMenu::update_balance_label(){
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
}

void WithdrawMenu::withdraw(){
    int amount = ui->amount_input->text().toInt();
    if (amount == 0) {
        showInfo("Amount should be positive number");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    }
    else{
        const Response<void>& responseWithdraw = accountActions.withdraw(AccountUpdateDto{currentToken._token, amount});
        if (responseWithdraw.is_success()){
            ui->amount_input->setStyleSheet("border: 1px solid green");
            showInfo("Withdraw successfully processed");
            update_balance_label();
        }
        else{
            showInfo(QString::fromStdString(responseWithdraw.get_error()));
        }
    }
    ui->amount_input->setText("");

};