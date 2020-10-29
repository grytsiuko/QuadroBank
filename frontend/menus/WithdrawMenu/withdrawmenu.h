#ifndef WITHDRAWMENU_H
#define WITHDRAWMENU_H

#include <QWidget>
#include "../utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_withdrawmenu.h"

namespace Ui {
class WithdrawMenu;
}

class WithdrawMenu : public QWidget, public Singleton<WithdrawMenu>
{
    Q_OBJECT

public:
    ~WithdrawMenu();

private:
    WithdrawMenu(QWidget *parent = nullptr) :
        QWidget(parent),
        ui(new Ui::WithdrawMenu)
    {
        ui->setupUi(this);
    }
    friend Singleton;
    friend object_ui<Ui::WithdrawMenu,WithdrawMenu>;
    Ui::WithdrawMenu *ui;
};

#endif // WITHDRAWMENU_H
