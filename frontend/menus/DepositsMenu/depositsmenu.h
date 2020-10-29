#ifndef DEPOSITSMENU_H
#define DEPOSITSMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_depositsmenu.h"

namespace Ui {
class DepositsMenu;
}

class DepositsMenu :  public QWidget, public Singleton<DepositsMenu>
{
    Q_OBJECT

public:

    ~DepositsMenu();

private:
    DepositsMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::DepositsMenu)
    {
        ui->setupUi(this);
    };
    friend Singleton;
    friend object_ui<Ui::DepositsMenu,DepositsMenu>;
    Ui::DepositsMenu *ui;
};

#endif // DEPOSITSMENU_H
