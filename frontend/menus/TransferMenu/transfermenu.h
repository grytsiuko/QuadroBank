#ifndef TRANSFERMENU_H
#define TRANSFERMENU_H

#include <QWidget>
#include "../utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_transfermenu.h"
namespace Ui {
class TransferMenu;
}

class TransferMenu : public QWidget, public Singleton<TransferMenu>
{
    Q_OBJECT

public:
    ~TransferMenu();

private:
    TransferMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::TransferMenu)
    {
        ui->setupUi(this);
    };
    friend Singleton;
    friend object_ui<Ui::TransferMenu,TransferMenu>;
    Ui::TransferMenu *ui;
};

#endif // TRANSFERMENU_H
