#include "loginmenu.h"
#include "QDebug"
#include "../../../backend/utils/response.h"
#include "../../../backend/account/dto/session_dto.h"
#include "../../../backend/account/dto/account_authorize_dto.h"

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
    Response<SessionDto> authorizeResponse = accountActions.authorize(
            AccountAuthorizeDto{card_data.toStdString(), pin_data.toStdString()}
    );
    // if input is correct, then emit signal to MainWindow, to provide MainMenu
    if (authorizeResponse.is_success()){
        TokenDto tokenDto = TokenDto{authorizeResponse.get_response()._token};
        emit input_validated();
        emit send_token(tokenDto);
        ui->card_number_input->setStyleSheet("border: 1px solid green");
        ui->password_input->setStyleSheet("border: 1px solid green");
        ui->card_number_input->setText("");

    }
    else{
        ui->card_number_input->setStyleSheet("border: 1px solid red");
        ui->password_input->setStyleSheet("border: 1px solid red");
    }
    ui->password_input->setText("");





};
