#ifndef LOGINMENU_H
#define LOGINMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_loginmenu.h"
#include "../../actions/account_actions.h"

namespace Ui {
    class LoginMenu;
}

class LoginMenu : public QWidget, public Singleton<LoginMenu> {
Q_OBJECT

public:
    ~LoginMenu();

signals:
    void input_validated();
    void send_token(TokenDto const &);

private slots:
    void login_validation();


private:
    explicit LoginMenu(QWidget *parent = nullptr) :
            QWidget(parent),
            ui(new Ui::LoginMenu) {
        ui->setupUi(this);

        disconnect(ui->enter_button, SIGNAL(clicked()), this, SLOT(login_validation()));
        connect(ui->enter_button, SIGNAL(clicked()), this, SLOT(login_validation()));
    };

    friend Singleton;
    friend object_ui<Ui::LoginMenu, LoginMenu>;
    AccountActions &accountActions = AccountActions::get_instance();
    TokenDto currentToken;
    Ui::LoginMenu *ui;
};


#endif // LOGINMENU_H
