#ifndef PAYMENTSMENU_H
#define PAYMENTSMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_paymentsmenu.h"
#include "../../actions/regular_payment_actions.h"
#include "iostream"
#include "frontend/menus/utils/date_utils/date_util.h"
#include "frontend/menus/utils/token_menu_interface/token_menu_interface.h"
namespace Ui {
    class PaymentsMenu;
}

class PaymentsMenu : public QWidget, public Singleton<PaymentsMenu>, TokenInterface {
Q_OBJECT

public:
    ~PaymentsMenu();

    void set_token(const SessionDto &token);

private slots:

    void edit(const QModelIndex &);

signals:
    void edit_payment(int);
    void go_update();
private:
    explicit PaymentsMenu(QWidget *parent = nullptr) :
            QWidget(parent),
            ui(new Ui::PaymentsMenu) {
        ui->setupUi(this);
        connect(ui->payments_table, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(edit(const QModelIndex &)));
    };

    void update_payments_list();

    friend Singleton;
    friend object_ui<Ui::PaymentsMenu, PaymentsMenu>;
    RegularPaymentActions &paymentsActions = RegularPaymentActions::get_instance();
    Ui::PaymentsMenu *ui;
};

#endif // PAYMENTSMENU_H
