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

void  PaymentsMenu::edit(const QModelIndex & index){
    RegularPaymentDto* currentPayment = new RegularPaymentDto;
    auto* currentModel = ui->payments_table->model();
    currentPayment->_id=currentModel->index(index.row(),3).data().toInt();
    currentPayment->_period_sec=currentModel->index(index.row(),0).data().toInt();
    currentPayment->_target_card=currentModel->index(index.row(),1).data().toString().toStdString();
    currentPayment->_sum=currentModel->index(index.row(),2).data().toInt();
    emit go_update();
    emit edit_payment(currentPayment);
}

void PaymentsMenu::update_payments_list() {
    const Response<vector<RegularPaymentDto>>& paymentsVectorResponse = paymentsActions.get_all_by_user(currentToken);

    if (paymentsVectorResponse.is_success()) {
        const vector<RegularPaymentDto>& paymentsVector = paymentsVectorResponse.get_response();

        auto* currentModel = new QStandardItemModel(paymentsVector.capacity(), 4);
        currentModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Period"));
        currentModel->setHeaderData(1, Qt::Horizontal, QObject::tr("To"));
        currentModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Amount"));
        currentModel->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));
        for (int i = 0; i < paymentsVector.capacity(); i++) {
            currentModel->setData(currentModel->index(i,0),paymentsVector.at(i)._period_sec);
            currentModel->setData(currentModel->index(i,1), QString::fromStdString(paymentsVector.at(i)._target_card));
            currentModel->setData(currentModel->index(i,2), paymentsVector.at(i)._sum);
            currentModel->setData(currentModel->index(i,3), paymentsVector.at(i)._id);
        }
        ui->payments_table->setModel(currentModel);
        ui->payments_table->setColumnHidden(4,true);
//      stretch table to fit all space
        for (int c = 0; c < (ui->payments_table->horizontalHeader()->count()); ++c)
        {
            ui->payments_table->horizontalHeader()->setSectionResizeMode(
                    c, QHeaderView::Stretch);
        }

    }
    else{
        std::cout << "Bad getter regular payment" << std::endl;
    }
}
