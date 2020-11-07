#ifndef UPDATEPAYMENTMENU_H
#define UPDATEPAYMENTMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_updatepaymentmenu.h"
#include "../../actions/regular_payment_actions.h"
#include "../../actions/account_actions.h"
#include "../utils/date_util.h"

namespace Ui {
    class UpdatePaymentMenu;
}

class UpdatePaymentMenu : public QWidget, public Singleton<UpdatePaymentMenu> {
Q_OBJECT

public:
    ~UpdatePaymentMenu();

    void set_token(const TokenDto &token);
signals:
    void updated();
public slots:
    void update_payment(const RegularPaymentDto*);
private slots:
    void send_update_dto();
    void send_delete_dto();

private:
    explicit UpdatePaymentMenu(QWidget *parent = nullptr) :
            QWidget(parent),
            ui(new Ui::UpdatePaymentMenu) {
        ui->setupUi(this);
        disconnect(ui->new_payment_button,SIGNAL(clicked()), this, SLOT(send_update_dto()));
        connect(ui->new_payment_button,SIGNAL(clicked()), this, SLOT(send_update_dto()));

        disconnect(ui->delete_button,SIGNAL(clicked()), this, SLOT(send_delete_dto()));
        connect(ui->delete_button,SIGNAL(clicked()), this, SLOT(send_delete_dto()));
    }

    void set_payment_date_variants();
    void update_balance_label();
    int payment_id = 0;
    friend Singleton;
    friend object_ui<Ui::UpdatePaymentMenu, UpdatePaymentMenu>;
    RegularPaymentActions &paymentActions = RegularPaymentActions::get_instance();
    AccountActions &accountActions = AccountActions::get_instance();
    TokenDto currentToken;
    Ui::UpdatePaymentMenu *ui;
};

#endif // UPDATEPAYMENTMENU_H
