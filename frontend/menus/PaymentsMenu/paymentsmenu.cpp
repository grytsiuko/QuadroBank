#include <QtGui/QStandardItemModel>
#include "paymentsmenu.h"

PaymentsMenu::~PaymentsMenu()
{
    delete ui;
}

void PaymentsMenu::set_token(const TokenDto &token) {

    currentToken = token;
    update_payments_list();
}

void PaymentsMenu::update_payments_list() {
    Response<vector<RegularPaymentDto>> paymentsVectorResponse = paymentsActions.get_all_by_user(currentToken);

    if (paymentsVectorResponse.is_success()) {
        const vector<RegularPaymentDto> *paymentsVector = paymentsVectorResponse.get_response();
        auto* currentModel = new QStandardItemModel(paymentsVector->capacity(), 3);
        currentModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Period"));
        currentModel->setHeaderData(1, Qt::Horizontal, QObject::tr("To"));
        currentModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Amount"));
        for (int i = 0; i < paymentsVector->capacity(); i++) {;
            currentModel->setData(currentModel->index(i,0),paymentsVector->at(i)._period_sec);
            currentModel->setData(currentModel->index(i,1), QString::fromStdString(paymentsVector->at(i)._target_card));
            currentModel->setData(currentModel->index(i,2), paymentsVector->at(i)._sum);
        }
        ui->payments_table->setModel(currentModel);

//      stretch table to fit all space
        for (int c = 0; c < (ui->payments_table->horizontalHeader()->count()); ++c)
        {
            ui->payments_table->horizontalHeader()->setSectionResizeMode(
                    c, QHeaderView::Stretch);
        }

    }
}
