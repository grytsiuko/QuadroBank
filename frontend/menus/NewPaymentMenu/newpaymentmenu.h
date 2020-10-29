#ifndef NEWPAYMENTMENU_H
#define NEWPAYMENTMENU_H

#include <QWidget>
#include "../utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_newpaymentmenu.h"

namespace Ui {
class NewPaymentMenu;
}

class NewPaymentMenu :  public QWidget, public Singleton<NewPaymentMenu>
{
    Q_OBJECT

public:

    ~NewPaymentMenu();

private:
    NewPaymentMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::NewPaymentMenu)
    {
        ui->setupUi(this);
    };
    friend Singleton;
    friend object_ui<Ui::NewPaymentMenu,NewPaymentMenu>;
    Ui::NewPaymentMenu *ui;
};

#endif // NEWPAYMENTMENU_H
