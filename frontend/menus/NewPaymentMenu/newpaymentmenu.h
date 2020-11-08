#ifndef NEWPAYMENTMENU_H
#define NEWPAYMENTMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_newpaymentmenu.h"
#include "../../actions/regular_payment_actions.h"
#include "../../actions/account_actions.h"

namespace Ui {
class NewPaymentMenu;
}

class NewPaymentMenu :  public QWidget, public Singleton<NewPaymentMenu>
{
    Q_OBJECT

public:
    void set_token(const TokenDto& token);
    ~NewPaymentMenu();
private slots:
    void create_payment();
private:
    explicit NewPaymentMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::NewPaymentMenu)
    {
        ui->setupUi(this);
        disconnect( ui->new_payment_button,SIGNAL(clicked()),this,SLOT(create_payment()));
        connect( ui->new_payment_button,SIGNAL(clicked()),this,SLOT(create_payment()));
        QRegExp re("^[0-9]+(\\.[0-9]{1,2})?$");
        QRegExpValidator *validator = new QRegExpValidator(re, this);
        ui->amount_input->setValidator(validator);
        QRegExp onlyNumber("^[0-9]+$");
        QRegExpValidator *number_validator = new QRegExpValidator(re, this);
        ui->card_input->setValidator(number_validator);
        ui->quantity_input->setValidator(number_validator);
    };
    void set_payment_date_variants();
    void update_balance_label();
    void set_up_date_time_edit();
    RegularPaymentActions &paymentActions = RegularPaymentActions::get_instance();
    AccountActions &accountActions = AccountActions::get_instance();
    TokenDto currentToken;
    friend Singleton;
    friend object_ui<Ui::NewPaymentMenu,NewPaymentMenu>;
    Ui::NewPaymentMenu *ui;
};

#endif // NEWPAYMENTMENU_H
