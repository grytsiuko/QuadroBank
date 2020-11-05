#include "newdepositmenu.h"


NewDepositMenu::~NewDepositMenu() {
    delete ui;
}

void NewDepositMenu::update_balance_label() {
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(currentToken);
    if (balanceDTO.is_success()) {
        const AccountBalanceDto *account_balance = balanceDTO.get_response();
        QString balanceString = QString("Your Balance: %1 $").arg(account_balance->_balance);
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
        const vector<DepositVariantDto> *depositVector = depositVectorResponse.get_response();

        for (const DepositVariantDto &dep_var : *depositVector) {
            cout << dep_var._period_sec << " " << dep_var._percentage << std::endl;
            QString balanceString = QString("Deposit for %1 with %2%").arg(dep_var._period_sec).arg(
                    dep_var._percentage);
            QString dataString = QString("%1.%2").arg(dep_var._percentage).arg(dep_var._period_sec);
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
        QStringList percentage_period = selected_variant.toString().split('.', Qt::SkipEmptyParts);
        cout << percentage_period.at(1).toLocal8Bit().constData() << std::endl;
        cout << percentage_period.at(0).toLocal8Bit().constData() << std::endl;
        Response<void> responseTransfer = depositActions.create(
                DepositCreateDto{currentToken._token,
                                 percentage_period.at(0).toLocal8Bit().toDouble(),
                                 percentage_period.at(1).toLocal8Bit().toInt()});
        if (responseTransfer.is_success()) {
            ui->amount_input->setText("");
            update_balance_label();
        }

    }

};
