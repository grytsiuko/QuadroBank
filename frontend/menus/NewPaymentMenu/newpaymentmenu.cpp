#include "newpaymentmenu.h"
#include "../../../backend/utils/time_intervals.h"
#include "QDate"
#include "frontend/menus/utils/info_message/info_message.h"
#include "../utils/update_balance_label/balance_label_util.h"
#include "../utils/amount_converter/amount_convert.h"

NewPaymentMenu::~NewPaymentMenu() {
    delete ui;
}

void NewPaymentMenu::update_balance_label() {
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(TokenDto{currentToken._token});
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        update_label(ui->LabelName, account_balance);
    }
}
void NewPaymentMenu::clear_inputs(){
    ui->amount_input->setText("");
    ui->card_input->setText("");
    ui->quantity_input->setText("");
};


void NewPaymentMenu::set_up_date_time_edit() {
    QDate today = QDate::currentDate();
    QTime now = QTime::currentTime();
    ui->dateTimeEdit->setDate(today);
    ui->dateTimeEdit->setMinimumDate(today);
    ui->dateTimeEdit->setTime(now);
    ui->dateTimeEdit->setMinimumTime(now);
};

void NewPaymentMenu::set_token(const SessionDto &token) {
    TokenInterface::set_token(token);
    update_balance_label();
    set_payment_date_variants();
    set_up_date_time_edit();
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
    int amount = convertAmount(ui->amount_input->text());
    if (amount == 0){
        showInfo("Amount cannot be 0");
        ui->amount_input->setStyleSheet("border: 1px solid red");
    }
    else {
        QString card = ui->card_input->text();
        if (card.length() < 1) {
            showInfo("Card input should not be empty");
            ui->card_input->setStyleSheet("border: 1px solid red");
        }
        else {
            int quantity = ui->quantity_input->text().toInt();
            if (quantity < 1) {
                showInfo("Quantity should not be empty");
                ui->quantity_input->setStyleSheet("border: 1px solid red");
            }
            else {
                QVariant selected_variant = ui->comboBox->currentData();
                int period = selected_variant.toInt() * quantity;
                time_t next_time = ui->dateTimeEdit->dateTime().toSecsSinceEpoch() + 1;
                const Response<void> responsePaymentCreation = paymentActions.create(
                        RegularPaymentCreateDto{
                                currentToken._token,
                                next_time,
                                period,
                                card.toStdString(),
                                amount
                        });
                if (responsePaymentCreation.is_success()) {
                    showInfo("Regular payment successfully created");
                    ui->amount_input->setText("");
                    ui->card_input->setText("");
                    ui->quantity_input->setText("");
                }
                else {
                    showInfo(QString::fromStdString(responsePaymentCreation.get_error()));
                }
            }
        }

    }
}