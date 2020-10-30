#ifndef NEWDEPOSITMENU_H
#define NEWDEPOSITMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_newdepositmenu.h"


namespace Ui {
class NewDepositMenu;
}

class NewDepositMenu :  public QWidget, public Singleton<NewDepositMenu>
{
    Q_OBJECT

public:
    ~NewDepositMenu();
private:
    NewDepositMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::NewDepositMenu)
    {
        ui->setupUi(this);
    };
    friend Singleton;
    friend object_ui<Ui::NewDepositMenu,NewDepositMenu>;
    Ui::NewDepositMenu *ui;
};

#endif // NEWDEPOSITMENU_H
