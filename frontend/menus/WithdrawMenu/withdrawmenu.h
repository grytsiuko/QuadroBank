#ifndef WITHDRAWMENU_H
#define WITHDRAWMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_withdrawmenu.h"
#include "../../actions/account_actions.h"

namespace Ui {
class WithdrawMenu;
}

class WithdrawMenu : public QWidget, public Singleton<WithdrawMenu>
{
    Q_OBJECT

public:
    ~WithdrawMenu();

    void set_token(const TokenDto& token);
    void update_balance_label();
public slots:
    void withdraw();

private:
    explicit WithdrawMenu(QWidget *parent = nullptr) :
        QWidget(parent),
        ui(new Ui::WithdrawMenu)
    {
        ui->setupUi(this);
        connect( ui->withdraw_button,SIGNAL(clicked()),this,SLOT(withdraw()));
    }
    friend Singleton;
    friend object_ui<Ui::WithdrawMenu,WithdrawMenu>;
    AccountActions &accountActions = AccountActions::get_instance();
    TokenDto currentToken;
    Ui::WithdrawMenu *ui;
};

#endif // WITHDRAWMENU_H
