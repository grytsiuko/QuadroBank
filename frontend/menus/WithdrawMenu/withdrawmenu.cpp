#include "withdrawmenu.h"
#include "ui_withdrawmenu.h"
#include "frontend/menus/utils/info_message/info_message.h"

WithdrawMenu::~WithdrawMenu()
{
    delete ui;
}

void WithdrawMenu::set_token(const TokenDto& token){
    TokenInterface::set_token(token);
    update_balance_label();
}

void WithdrawMenu::update_balance_label(){
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

void WithdrawMenu::withdraw(){
    bool good;
    double amount = ui->amount_input->text().toDouble(&good);
    if (!good) {
        showInfo("Amount should be positive number");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    }
    else if (amount <= 0.001){
        showInfo("Amount cannot be 0");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    }
    else{
        const Response<void>& responseWithdraw = accountActions.withdraw(
                AccountUpdateDto{currentToken._token,
                                 static_cast<int>(amount*100)});
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