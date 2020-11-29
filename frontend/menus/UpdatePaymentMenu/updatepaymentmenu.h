#ifndef UPDATEPAYMENTMENU_H
#define UPDATEPAYMENTMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_updatepaymentmenu.h"
#include "../../actions/regular_payment_actions.h"
#include "../../actions/account_actions.h"
#include "frontend/menus/utils/token_menu_interface/token_menu_interface.h"
#include "frontend/menus/utils/date_utils/date_util.h"

namespace Ui {
    class UpdatePaymentMenu;
}

class UpdatePaymentMenu : public QWidget, public Singleton<UpdatePaymentMenu>, TokenInterface {
Q_OBJECT

public:
    ~UpdatePaymentMenu();

    void set_token(const SessionDto &token);
signals:
    void updated();
public slots:
    void update_payment(int);
private slots:
    void send_update_dto();
    void send_delete_dto();
    void clear_inputs();

private:
    explicit UpdatePaymentMenu(QWidget *parent = nullptr) :
            QWidget(parent),
            ui(new Ui::UpdatePaymentMenu) {
        ui->setupUi(this);
        connect(ui->new_payment_button,SIGNAL(clicked()), this, SLOT(send_update_dto()));
        connect(ui->delete_button,SIGNAL(clicked()), this, SLOT(send_delete_dto()));
        connect(ui->back_button,SIGNAL(clicked()), this, SLOT(clear_inputs()));

        QRegExp re("^[0-9]+(\\.[0-9]{1,2})?$");
        QRegExpValidator *validator = new QRegExpValidator(re, this);
        ui->amount_input->setValidator(validator);

        QRegExp onlyNumber("^[0-9]+$");
        QRegExpValidator *number_validator = new QRegExpValidator(re, this);
        ui->card_input->setValidator(number_validator);
        ui->quantity_input->setValidator(number_validator);
    }

    void set_payment_date_variants();
    void update_balance_label();
    void set_up_date_time_edit();
    int payment_id = 0;
    friend Singleton;
    friend object_ui<Ui::UpdatePaymentMenu, UpdatePaymentMenu>;
    RegularPaymentActions &paymentActions = RegularPaymentActions::get_instance();
    AccountActions &accountActions = AccountActions::get_instance();
    Ui::UpdatePaymentMenu *ui;
};

#endif // UPDATEPAYMENTMENU_H
