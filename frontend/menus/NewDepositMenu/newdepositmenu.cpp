#include "newdepositmenu.h"
#include "frontend/menus/utils/info_message/info_message.h"
#include "../utils/update_balance_label/balance_label_util.h"
#include "../utils/amount_converter/amount_convert.h"
NewDepositMenu::~NewDepositMenu() {
    delete ui;
}

void NewDepositMenu::update_balance_label() {
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(TokenDto{currentToken._token});
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        update_label(ui->LabelName, account_balance);
    }
}

void NewDepositMenu::set_token(const SessionDto &token) {
    TokenInterface::set_token(token);
    update_balance_label();
    load_deposit_variants();
}

void NewDepositMenu::clear_inputs(){
    ui->amount_input->setText("");
};

void NewDepositMenu::load_deposit_variants() {
    Response<vector<DepositVariantDto>> depositVectorResponse = depositActions.get_possible_variants(TokenDto{currentToken._token});
    if (depositVectorResponse.is_success()) {
        const vector<DepositVariantDto>& depositVector = depositVectorResponse.get_response();
        ui->comboBox->clear();
        for (const DepositVariantDto &dep_var : depositVector) {
            QString balanceString = QString("Deposit for %1s with %2%").arg(dep_var._period_sec).arg(
                    dep_var._percentage*100);
            QString dataString = QString("%1").arg(dep_var._percentage);
            ui->comboBox->addItem(balanceString, dataString);
        }

    }
}

void NewDepositMenu::create_deposit() {
    int amount = convertAmount(ui->amount_input->text());
    if (amount == 0){
        showInfo("Amount cannot be 0");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    }
    else {
        QVariant selected_variant = ui->comboBox->currentData();
        const Response<void>& responseTransfer = depositActions.create(
                DepositCreateDto{currentToken._token,
                                 selected_variant.toDouble(),
                                 amount});
        if (responseTransfer.is_success()) {
            ui->amount_input->setText("");
            showInfo("Deposit successfully created");
            update_balance_label();
        }
        else{
            showInfo(QString::fromStdString(responseTransfer.get_error()));
        }
        ui->amount_input->setStyleSheet("");
    }

};
