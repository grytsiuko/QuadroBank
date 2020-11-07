#include "newdepositmenu.h"


NewDepositMenu::~NewDepositMenu() {
    delete ui;
}

void NewDepositMenu::update_balance_label() {
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(currentToken);
    if (balanceDTO.is_success()) {
        const AccountBalanceDto account_balance = balanceDTO.get_response();
        QString balanceString = QString("Your Balance: %1 $").arg(account_balance._balance);
        ui->LabelName->setText(balanceString);
    }
}

void NewDepositMenu::set_token(const TokenDto &token) {
    currentToken = token;
    update_balance_label();
    load_deposit_variants();
}

void NewDepositMenu::load_deposit_variants() {
    Response<vector<DepositVariantDto>> depositVectorResponse = depositActions.get_possible_variants(currentToken);

    if (depositVectorResponse.is_success()) {
        const vector<DepositVariantDto>& depositVector = depositVectorResponse.get_response();
        ui->comboBox->clear();
        for (const DepositVariantDto &dep_var : depositVector) {
            QString balanceString = QString("Deposit for %1 with %2%").arg(dep_var._period_sec).arg(
                    dep_var._percentage*100);

            QString dataString = QString("%1").arg(dep_var._percentage);
            ui->comboBox->addItem(balanceString, dataString);
        }

    }
}

void NewDepositMenu::create_deposit() {
    int amount = ui->amount_input->text().toInt();
    if (amount < 1) {
        ui->amount_input->setStyleSheet("border: 1px solid red");
        ui->amount_input->setText("");
    } else {
        QVariant selected_variant = ui->comboBox->currentData();
        const Response<void>& responseTransfer = depositActions.create(
                DepositCreateDto{currentToken._token,
                                 selected_variant.toDouble(),
                                 amount});
        if (responseTransfer.is_success()) {
            ui->amount_input->setText("");
            update_balance_label();
        }

    }

};
