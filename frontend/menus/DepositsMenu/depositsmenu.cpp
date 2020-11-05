#include "depositsmenu.h"
#include "ui_depositsmenu.h"
#include <QStandardItemModel>

DepositsMenu::~DepositsMenu()
{
    delete ui;
}

void DepositsMenu::set_token(const TokenDto &token) {
    currentToken = token;
    update_deposits_list();
}

void DepositsMenu::update_deposits_list(){
    Response<vector<DepositDto>> depositVectorResponse = depositActions.get_all_by_user(currentToken);

    if (depositVectorResponse.is_success()){
        const vector<DepositDto>* depositVector = depositVectorResponse.get_response();
        QStandardItemModel model(depositVector->capacity(),4);
        for (int i = 0; i < depositVector->capacity(); i++){
            model.setItem(i,0, new QStandardItem(depositVector->at(i)._start_date));
            model.setItem(i,1, new QStandardItem(depositVector->at(i)._end_date));
            model.setItem(i,2, new QStandardItem(depositVector->at(i)._percentage));
            model.setItem(i,3, new QStandardItem(depositVector->at(i)._sum));
        }
        ui->deposits_table->setModel(&model);
//        for (const DepositDto& dep_var : *depositVector){
//            cout << dep_var._start_date << " " << dep_var._period_sec
//            << " " << dep_var._percentage << " "<< dep_var._sum << std::endl;
//            QStandardItem* deposit_item = new QStandardItem(QString"");
//
//        }
    }
}
