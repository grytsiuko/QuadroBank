#ifndef LOGINMENU_H
#define LOGINMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_loginmenu.h"

namespace Ui {
class LoginMenu;
}

class LoginMenu : public QWidget, public Singleton<LoginMenu>
{
    Q_OBJECT

signals:
    void input_validated();

private slots:
    void login_validation();


public:
    ~LoginMenu();

private:
    LoginMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::LoginMenu)
    {
        ui->setupUi(this);
        connect(ui->enter_button, SIGNAL(clicked()),this,SLOT(login_validation()));
    };

    friend Singleton;
    friend object_ui<Ui::LoginMenu,LoginMenu>;
    Ui::LoginMenu *ui;
};


#endif // LOGINMENU_H
