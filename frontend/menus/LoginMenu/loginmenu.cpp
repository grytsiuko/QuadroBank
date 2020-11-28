#include "loginmenu.h"
#include "QDebug"
#include "frontend/menus/utils/info_message/info_message.h"

LoginMenu::~LoginMenu()
{
    delete ui;
}

void LoginMenu::clear_stylesheet(){
    ui->card_number_input->setStyleSheet("");
    ui->password_input->setStyleSheet("");
}

void LoginMenu::login_validation(){
    //getting input data
    QString card_data = ui->card_number_input->text();
    QString pin_data = ui->password_input->text();

    const Response<SessionDto>& authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{card_data.toStdString(), pin_data.toStdString()}
    );
    if (authorizeResponse.is_success()){
        const SessionDto& sessionDto = authorizeResponse.get_response();
        emit send_token(sessionDto);
        emit input_validated();
        clear_stylesheet();
        ui->card_number_input->setText("");
    }
    else{
        ui->card_number_input->setStyleSheet("border: 1px solid red");
        ui->password_input->setStyleSheet("border: 1px solid red");
        showInfo(QString::fromStdString(authorizeResponse.get_error()));
    }
    ui->password_input->setText("");
};
