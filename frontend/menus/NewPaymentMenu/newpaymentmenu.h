#ifndef NEWPAYMENTMENU_H
#define NEWPAYMENTMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_newpaymentmenu.h"
#include "../../actions/regular_payment_actions.h"
#include "../../actions/account_actions.h"
#include "frontend/menus/utils/token_menu_interface/token_menu_interface.h"

namespace Ui {
class NewPaymentMenu;
}

class NewPaymentMenu :  public QWidget, public Singleton<NewPaymentMenu>,  TokenInterface
{
    Q_OBJECT

public:
    void set_token(const SessionDto& token);
    ~NewPaymentMenu();
private slots:
    void create_payment();
    void clear_inputs();
private:
    explicit NewPaymentMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::NewPaymentMenu)
    {
        ui->setupUi(this);
        connect( ui->new_payment_button,SIGNAL(clicked()),this,SLOT(create_payment()));
        connect( ui->back_button,SIGNAL(clicked()),this,SLOT(clear_inputs()));

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

    friend Singleton;
    friend object_ui<Ui::NewPaymentMenu,NewPaymentMenu>;

    RegularPaymentActions &paymentActions = RegularPaymentActions::get_instance();
    AccountActions &accountActions = AccountActions::get_instance();
    Ui::NewPaymentMenu *ui;
};

#endif // NEWPAYMENTMENU_H
