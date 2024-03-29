#include "updatepaymentmenu.h"
#include <iostream>
#include <QtCore/QDate>
#include "frontend/menus/utils/info_message/info_message.h"
#include "../utils/update_balance_label/balance_label_util.h"
#include "../utils/amount_converter/amount_convert.h"
UpdatePaymentMenu::~UpdatePaymentMenu() {
    delete ui;
}

void UpdatePaymentMenu::set_token(const SessionDto &token) {
    TokenInterface::set_token(token);
}

void UpdatePaymentMenu::update_balance_label(){
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(TokenDto{currentToken._token});
    if (balanceDTO.is_success()) {
        const AccountBalanceDto& account_balance = balanceDTO.get_response();
        update_label(ui->LabelName, account_balance);
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
void UpdatePaymentMenu::clear_inputs(){
    ui->amount_input->setText("");
    ui->card_input->setText("");
    ui->quantity_input->setText("");
}


void UpdatePaymentMenu::update_payment(int currentPaymentId) {
    set_payment_date_variants();
    update_balance_label();
    set_up_date_time_edit();
    Response<RegularPaymentDto> currentPaymentResponse =
            paymentActions.get_by_id(RegularPaymentGetDto{currentToken._token, currentPaymentId});
    if (currentPaymentResponse.is_success()){
        const RegularPaymentDto& currentPayment = currentPaymentResponse.get_response();
        const QuantityPeriod *quantityPeriod = get_quantity_and_period(currentPayment._period_sec);
        ui->amount_input->setText(QString::number(1.*currentPayment._sum/100));
        ui->card_input->setText(QString::fromStdString(currentPayment._target_card));
        ui->quantity_input->setText(QString::number(quantityPeriod->quantity));
        payment_id = currentPaymentId;
        int index = ui->comboBox->findData(quantityPeriod->period);
        if (index != -1) {
            ui->comboBox->setCurrentIndex(index);
        }
        delete quantityPeriod;
        ui->dateTimeEdit->setDateTime(QDateTime::fromTime_t(currentPayment._next_time));
    }
    else{
        std::cout << "Problem with getting rp by id: "<< currentPaymentResponse.get_error() << std::endl;
    }
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
        } else {
            int quantity = ui->quantity_input->text().toInt();
            if (quantity < 1) {
                showInfo("Quantity should be positive number");
                ui->quantity_input->setStyleSheet("border: 1px solid red");
            } else {
                QVariant selected_variant = ui->comboBox->currentData();
                int period = selected_variant.toInt() * quantity;
                time_t next_time = ui->dateTimeEdit->dateTime().toSecsSinceEpoch() + period;

                const Response<void> responseUpdatePayment =
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
                    showInfo("Regular payment was successfully Updated");
                    emit updated();
                }
                else {
                    showInfo(QString::fromStdString(responseUpdatePayment.get_error()));
                }
            }
        }

    }

}