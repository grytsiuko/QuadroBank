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
        connect( ui->new_payment_button,SIGNAL(clicked()),this,SLOT(create_payment()));
    };
    void set_payment_date_variants();
    void update_balance_label();
    RegularPaymentActions &paymentActions = RegularPaymentActions::get_instance();
    AccountActions &accountActions = AccountActions::get_instance();
    TokenDto currentToken;
    friend Singleton;
    friend object_ui<Ui::NewPaymentMenu,NewPaymentMenu>;
    Ui::NewPaymentMenu *ui;
};

#endif // NEWPAYMENTMENU_H
