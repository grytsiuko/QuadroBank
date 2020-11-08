#include "loginmenu.h"
#include "QDebug"
#include "../utils/info_message.h"

LoginMenu::~LoginMenu()
{
    delete ui;
}
void LoginMenu::login_validation(){
    //getting input data
    QString card_data = ui->card_number_input->text();
    QString pin_data = ui->password_input->text();
    // debug info
    qInfo() << "Card Number input: "<< card_data;
    qInfo() << "Pin input: "<< pin_data;
    const Response<SessionDto>& authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{card_data.toStdString(), pin_data.toStdString()}
    );
    // if input is correct, then emit signal to MainWindow, to provide MainMenu
    if (authorizeResponse.is_success()){
        TokenDto tokenDto = TokenDto{authorizeResponse.get_response()._token};
        emit send_token(tokenDto);
        emit input_validated();
        ui->card_number_input->setText("");

    }
    else{
        ui->card_number_input->setStyleSheet("border: 1px solid red");
        ui->password_input->setStyleSheet("border: 1px solid red");
        showInfo(QString::fromStdString(authorizeResponse.get_error()));
    }
    ui->password_input->setText("");





};
