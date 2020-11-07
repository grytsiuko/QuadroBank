#include "newpaymentmenu.h"
#include "../../../backend/utils/time_intervals.h"
#include "QDate"

NewPaymentMenu::~NewPaymentMenu() {
    delete ui;
}

void NewPaymentMenu::update_balance_label() {
    Response<AccountBalanceDto> balanceDTO = accountActions.check_balance(currentToken);
    if (balanceDTO.is_success()) {
        const AccountBalanceDto &account_balance = balanceDTO.get_response();
        QString balanceString;
        if (account_balance._is_credit)
            balanceString = QString("Your Balance: %1 $ (Cred Limit: %2)").arg(account_balance._balance).arg(
                    account_balance._credit_limit);
        else
            balanceString = QString("Your Balance: %1 $").arg(account_balance._balance);
        ui->LabelName->setText(balanceString);
    }
}

void NewPaymentMenu::set_up_date_time_edit() {
    QDate today = QDate::currentDate();
    QTime now = QTime::currentTime();
    ui->dateTimeEdit->setDate(today);
    ui->dateTimeEdit->setMinimumDate(today);
    ui->dateTimeEdit->setTime(now);
    ui->dateTimeEdit->setMinimumTime(now);
};

void NewPaymentMenu::set_token(const TokenDto &token) {
    currentToken = token;
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
                if (ui->dateTimeEdit->dateTime() < QDateTime::currentDateTime()){
                    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
                }
                QVariant selected_variant = ui->comboBox->currentData();
                int period = selected_variant.toInt() * quantity;
                time_t next_time = ui->dateTimeEdit->dateTime().toSecsSinceEpoch() + period;

                const Response<void> &responsePaymentCreation = paymentActions.create(
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
                } else {
                    std::cout << responsePaymentCreation.get_error() << std::endl;
                }
            }
        }

    }
}