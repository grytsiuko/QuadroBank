#include "newpaymentmenu.h"
#include "../../../backend/utils/time_intervals.h"


NewPaymentMenu::~NewPaymentMenu() {
    delete ui;
}

void NewPaymentMenu::update_balance_label() {
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(currentToken);
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        QString balanceString = QString::number(account_balance._balance);
        ui->LabelName->setText(balanceString);
    }
}

void NewPaymentMenu::set_token(const TokenDto &token) {
    currentToken = token;
    update_balance_label();
    set_payment_date_variants();
}

void NewPaymentMenu::set_payment_date_variants() {
    ui->comboBox->clear();
    ui->comboBox->addItem("Seconds", TimeIntervals::SECOND);
    ui->comboBox->addItem("Minutes", TimeIntervals::MINUTE);
    ui->comboBox->addItem("Hours", TimeIntervals::HOUR);
    ui->comboBox->addItem("Days", TimeIntervals::DAY);
    ui->comboBox->addItem("Month", TimeIntervals::MONTH);
};

void NewPaymentMenu::create_payment() {
    int amount = ui->amount_input->text().toInt();
    if (amount < 1) {
        ui->amount_input->setStyleSheet("border: 1px solid red");
        ui->amount_input->setText("");
    } else {
        QString card = ui->card_input->text();
        if (card.length() < 1) {
            ui->card_input->setStyleSheet("border: 1px solid red");
        } else {
            int quantity = ui->quantity_input->text().toInt();
            if (quantity < 1) {
                ui->quantity_input->setStyleSheet("border: 1px solid red");
            } else {
                QVariant selected_variant = ui->comboBox->currentData();
                int period = selected_variant.toInt() * quantity;
                time_t next_time = time(nullptr) + period;

                const Response<void>& responsePaymentCreation = paymentActions.create(
                        RegularPaymentCreateDto{
                                currentToken._token,
                                next_time,
                                period,
                                card.toStdString(),
                                amount
                        });
                if (responsePaymentCreation.is_success()) {
                    ui->amount_input->setText("");
                    ui->card_input->setText("");
                    ui->quantity_input->setText("");
                }
                else{
                    std::cout<< responsePaymentCreation.get_error() << std::endl;
                }
            }
        }

    }
}