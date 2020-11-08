#include "updatepaymentmenu.h"
#include <iostream>
#include <QtCore/QDate>
#include "../utils/info_message.h"

UpdatePaymentMenu::~UpdatePaymentMenu() {
    delete ui;
}

void UpdatePaymentMenu::set_token(const TokenDto &token) {
    currentToken = token;
}

void UpdatePaymentMenu::update_balance_label(){
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

void UpdatePaymentMenu::set_up_date_time_edit() {
    QDate today = QDate::currentDate();
    QTime now = QTime::currentTime();
    ui->dateTimeEdit->setDate(today);
    ui->dateTimeEdit->setMinimumDate(today);
    ui->dateTimeEdit->setTime(now);
    ui->dateTimeEdit->setMinimumTime(now);
};


void UpdatePaymentMenu::set_payment_date_variants() {
    ui->comboBox->clear();
    ui->comboBox->addItem("Seconds", TimeIntervals::SECOND);
    ui->comboBox->addItem("Minutes", TimeIntervals::MINUTE);
    ui->comboBox->addItem("Hours", TimeIntervals::HOUR);
    ui->comboBox->addItem("Days", TimeIntervals::DAY);
    ui->comboBox->addItem("Month", TimeIntervals::MONTH);
};



void UpdatePaymentMenu::update_payment(const RegularPaymentDto *currentPayment) {
    set_payment_date_variants();
    update_balance_label();
    QuantityPeriod *quantityPeriod = get_quantity_and_period(currentPayment->_period_sec);

    ui->amount_input->setText(QString::number(currentPayment->_sum));
    ui->card_input->setText(QString::fromStdString(currentPayment->_target_card));
    ui->quantity_input->setText(QString::number(quantityPeriod->quantity));
    payment_id = currentPayment->_id;
    int index = ui->comboBox->findData(quantityPeriod->period);
    if (index != -1) {
        ui->comboBox->setCurrentIndex(index);
    }
    delete quantityPeriod;
}

void UpdatePaymentMenu::send_delete_dto(){
    const Response<void>& responseDeletePayment =
            paymentActions.remove(RegularPaymentDeleteDto{
                currentToken._token,
                payment_id
            });
    if (responseDeletePayment.is_success()){
        ui->amount_input->setText("");
        ui->card_input->setText("");
        ui->quantity_input->setText("");
        showInfo("Regular payment was successfully deleted");
        emit updated();
    }
    else {
        showInfo(QString::fromStdString(responseDeletePayment.get_error()));
    }

}


void UpdatePaymentMenu::send_update_dto(){
    int amount = ui->amount_input->text().toInt();
    if (amount < 1) {
        ui->amount_input->setStyleSheet("border: 1px solid red");
        showInfo("Amount should be positive number");
        ui->amount_input->setText("");
    } else {
        QString card = ui->card_input->text();
        if (card.length() < 1) {
            showInfo("Card input should not be empty");
            ui->card_input->setStyleSheet("border: 1px solid red");
        } else {
            int quantity = ui->quantity_input->text().toInt();
            if (quantity < 1) {
                showInfo("Quantity should be positive number");
                ui->quantity_input->setStyleSheet("border: 1px solid red");
            } else {
                if (ui->dateTimeEdit->dateTime() < QDateTime::currentDateTime()){
                    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
                }
                QVariant selected_variant = ui->comboBox->currentData();
                int period = selected_variant.toInt() * quantity;
                time_t next_time = ui->dateTimeEdit->dateTime().toSecsSinceEpoch() + period;

                const Response<void>& responseUpdatePayment =
                        paymentActions.update(RegularPaymentUpdateDto{
                                currentToken._token,
                                payment_id,
                                period,
                                next_time,
                                card.toStdString(),
                                amount
                        });
                if (responseUpdatePayment.is_success()) {
                    ui->amount_input->setText("");
                    ui->card_input->setText("");
                    ui->quantity_input->setText("");
                    showInfo("Regular payment was successfully created");
                    emit updated();
                }
                else {
                    showInfo(QString::fromStdString(responseUpdatePayment.get_error()));
                }
            }
        }

    }

}