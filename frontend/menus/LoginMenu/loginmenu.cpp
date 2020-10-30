#include "loginmenu.h"
#include "QDebug"

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
    // if input is correct, then emit signal to MainWindow, to provide MainMenu
    emit input_validated();
    // clear inputs
    ui->card_number_input->setText("");
    ui->password_input->setText("");
};
