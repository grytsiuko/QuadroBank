#include "depositsmenu.h"
#include "ui_depositsmenu.h"
#include <QStandardItemModel>
#include "../utils/date_util.h"
DepositsMenu::~DepositsMenu() {
    delete ui;
}

void DepositsMenu::set_token(const TokenDto &token) {
    currentToken = token;
    update_deposits_list();
}



void DepositsMenu::update_deposits_list() {
    Response<vector<DepositDto>> depositVectorResponse = depositActions.get_all_by_user(currentToken);

    if (depositVectorResponse.is_success()) {
        const vector<DepositDto> *depositVector = depositVectorResponse.get_response();
        auto* currentModel = new QStandardItemModel(depositVector->capacity(), 4);
        currentModel->setHeaderData(0, Qt::Horizontal, QObject::tr("Start Date"));
        currentModel->setHeaderData(1, Qt::Horizontal, QObject::tr("End Date"));
        currentModel->setHeaderData(2, Qt::Horizontal, QObject::tr("%"));
        currentModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Amount"));
        for (int i = 0; i < depositVector->capacity(); i++) {;
            currentModel->setData(currentModel->index(i,0), create_date_from_unix(depositVector->at(i)._start_date));
            currentModel->setData(currentModel->index(i,1), create_date_from_unix(depositVector->at(i)._end_date));
            currentModel->setData(currentModel->index(i,2), depositVector->at(i)._percentage);
            currentModel->setData(currentModel->index(i,3), depositVector->at(i)._sum);

        }

        ui->deposits_table->setModel(currentModel);

//      stretch table to fit all space
        for (int c = 0; c < (ui->deposits_table->horizontalHeader()->count()); ++c)
        {
            ui->deposits_table->horizontalHeader()->setSectionResizeMode(
                    c, QHeaderView::Stretch);
        }

    }
}
