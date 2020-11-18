#ifndef TRANSFERMENU_H
#define TRANSFERMENU_H

#include <QWidget>
#include "QRegExpValidator"
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_transfermenu.h"
#include "../../actions/account_actions.h"
#include "frontend/menus/utils/token_menu_interface/token_menu_interface.h"

namespace Ui {
class TransferMenu;
}

class TransferMenu : public QWidget, public Singleton<TransferMenu>,  TokenInterface
{
    Q_OBJECT

public:
    ~TransferMenu();
    void update_balance_label();
    void set_token(const TokenDto& token);

public slots:
    void transfer();

private:
    explicit TransferMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::TransferMenu)
    {
        ui->setupUi(this);
        disconnect( ui->transfer_button,SIGNAL(clicked()),this,SLOT(transfer()));
        connect( ui->transfer_button,SIGNAL(clicked()),this,SLOT(transfer()));

        QRegExp re("^[0-9]+(\\.[0-9]{1,2})?$");
        QRegExpValidator *validator = new QRegExpValidator(re, this);
        ui->amount_input->setValidator(validator);

        QRegExp onlyNumber("^[0-9]+$");
        QRegExpValidator *number_validator = new QRegExpValidator(re, this);
        ui->card_number_input->setValidator(number_validator);
    };
    friend Singleton;
    friend object_ui<Ui::TransferMenu,TransferMenu>;
    AccountActions &accountActions = AccountActions::get_instance();
    Ui::TransferMenu *ui;
};

#endif // TRANSFERMENU_H
