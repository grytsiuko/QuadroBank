#ifndef REFILLMENU_H
#define REFILLMENU_H

#include <QWidget>
#include "../utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_refillmenu.h"

namespace Ui {
class RefillMenu;
}

class RefillMenu : public QWidget, public Singleton<RefillMenu>
{
    Q_OBJECT

public:
    ~RefillMenu();

private:
    RefillMenu(QWidget *parent = nullptr) :
        QWidget(parent),
        ui(new Ui::RefillMenu)
    {

        ui->setupUi(this);
    }
    friend Singleton;
    friend object_ui<Ui::RefillMenu,RefillMenu>;
    Ui::RefillMenu *ui;
};

#endif // REFILLMENU_H
