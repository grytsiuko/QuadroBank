#ifndef PAYMENTSMENU_H
#define PAYMENTSMENU_H

#include <QWidget>
#include "../utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_paymentsmenu.h"

namespace Ui {
class PaymentsMenu;
}

class PaymentsMenu :  public QWidget, public Singleton<PaymentsMenu>
{
    Q_OBJECT

public:

    ~PaymentsMenu();

private:
    PaymentsMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::PaymentsMenu)
    {
        ui->setupUi(this);
    };
    friend Singleton;
    friend object_ui<Ui::PaymentsMenu,PaymentsMenu>;
    Ui::PaymentsMenu *ui;
};

#endif // PAYMENTSMENU_H
