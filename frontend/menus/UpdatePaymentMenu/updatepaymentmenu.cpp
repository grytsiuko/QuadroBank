#include "updatepaymentmenu.h"
#include "../../../backend/utils/time_intervals.h"
#include <iostream>

UpdatePaymentMenu::~UpdatePaymentMenu() {
    delete ui;
}

void UpdatePaymentMenu::set_token(const TokenDto &token) {
    currentToken = token;
}

void UpdatePaymentMenu::set_payment_date_variants() {
    ui->comboBox->clear();
    ui->comboBox->addItem("Seconds", TimeIntervals::SECOND);
    ui->comboBox->addItem("Minutes", TimeIntervals::MINUTE);
    ui->comboBox->addItem("Hours", TimeIntervals::HOUR);
    ui->comboBox->addItem("Days", TimeIntervals::DAY);
    ui->comboBox->addItem("Month", TimeIntervals::MONTH);
};

QuantityPeriod *UpdatePaymentMenu::get_quantity_and_period(int period_sec) {
    int currentSeconds = period_sec;
    auto *res = new QuantityPeriod{0, 0};
    int periods[5] = {TimeIntervals::SECOND, TimeIntervals::MINUTE,
                      TimeIntervals::HOUR, TimeIntervals::DAY,
                      TimeIntervals::MONTH};
    int i;
    for (i = 0; i < 5; ++i) {
        if (currentSeconds / periods[i] < 1) {
            break;
        }
    }
    res->period = periods[i-1];
    res->quantity = period_sec / (res->period);
    return res;
}

void UpdatePaymentMenu::update_payment(const RegularPaymentDto *currentPayment) {
    set_payment_date_variants();
    QuantityPeriod *quantityPeriod = get_quantity_and_period(currentPayment->_period_sec);
    ui->amount_input->setText(QString::number(currentPayment->_sum));
    ui->card_input->setText(QString::fromStdString(currentPayment->_target_card));
    ui->quantity_input->setText(QString::number(quantityPeriod->quantity));
    payment_id = currentPayment->_id;
    int index = ui->comboBox->findData(quantityPeriod->period);
    if (index != -1) {
        ui->comboBox->setCurrentIndex(index);
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
        emit updated();
    }

}


void UpdatePaymentMenu::send_update_dto(){
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
                    emit updated();
                }
            }
        }

    }

}