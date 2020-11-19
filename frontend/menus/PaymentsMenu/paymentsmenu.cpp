#include <QtGui/QStandardItemModel>
#include "paymentsmenu.h"
#include "QDateTime"
PaymentsMenu::~PaymentsMenu()
{
    delete ui;
}

void PaymentsMenu::set_token(const TokenDto &token) {
    TokenInterface::set_token(token);
    update_payments_list();
}

void PaymentsMenu::edit(const QModelIndex & index){
    auto* currentModel = ui->payments_table->model();
    emit go_update();
    emit edit_payment(currentModel->index(index.row(),4).data().toInt());
}

void PaymentsMenu::update_payments_list() {
    const Response<vector<RegularPaymentDto>>& paymentsVectorResponse = paymentsActions.get_all_by_user(currentToken);

    if (paymentsVectorResponse.is_success()) {
        const vector<RegularPaymentDto>& paymentsVector = paymentsVectorResponse.get_response();

        auto* currentModel = new QStandardItemModel(paymentsVector.capacity(), 6);
        currentModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Next"));
        currentModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Period"));
        currentModel->setHeaderData(2, Qt::Horizontal, QObject::tr("To"));
        currentModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Amount"));
        currentModel->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
        currentModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Period-normal"));
        for (int i = 0; i < paymentsVector.capacity(); i++) {
            const QuantityPeriod* quantityPeriod = get_quantity_and_period(paymentsVector.at(i)._period_sec);

            currentModel->setData(currentModel->index(i,0), QDateTime::fromTime_t(paymentsVector.at(i)._next_time).toString("dd.MM.yyyy\nH:mm:ss"));
            currentModel->setData(currentModel->index(i,1), QString("%1 %2").arg(quantityPeriod->quantity)
            .arg(get_name_of_interval(quantityPeriod->period)));
            currentModel->setData(currentModel->index(i,2), QString::fromStdString(paymentsVector.at(i)._target_card));
            currentModel->setData(currentModel->index(i,3), 1.*paymentsVector.at(i)._sum/100);
            currentModel->setData(currentModel->index(i,4), paymentsVector.at(i)._id);
            currentModel->setData(currentModel->index(i,5), paymentsVector.at(i)._period_sec);
            delete quantityPeriod;
        }
        ui->payments_table->setModel(currentModel);
        QFont comic("Comic Sans MS", 14);
        ui->payments_table->setFont(comic);
        for (int i = 0; i < paymentsVector.capacity(); ++i) {
            ui->payments_table->setRowHeight(i,75);
        }

        ui->payments_table->setColumnHidden(4,true);
        ui->payments_table->setColumnHidden(5,true);
//      stretch table to fit all space
        for (int c = 0; c < (ui->payments_table->horizontalHeader()->count()); ++c)
        {
            ui->payments_table->horizontalHeader()->setSectionResizeMode(
                    c, QHeaderView::Stretch);
            ui->payments_table->horizontalHeader()->setFont(comic);
        }

    }

}
