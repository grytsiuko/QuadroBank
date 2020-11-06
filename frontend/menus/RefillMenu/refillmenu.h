#ifndef REFILLMENU_H
#define REFILLMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_refillmenu.h"
#include "../../actions/account_actions.h"

namespace Ui {
class RefillMenu;
}

class RefillMenu : public QWidget, public Singleton<RefillMenu>
{
    Q_OBJECT

public:
    ~RefillMenu();
    void update_balance_label();
    void set_token(const TokenDto& token);

public slots:
    void refill();

private:
    RefillMenu(QWidget *parent = nullptr) :
        QWidget(parent),
        ui(new Ui::RefillMenu)
    {

        ui->setupUi(this);

        disconnect( ui->refill_button,SIGNAL(clicked()),this,SLOT(refill()));
        connect( ui->refill_button,SIGNAL(clicked()),this,SLOT(refill()));
    }
    friend Singleton;
    friend object_ui<Ui::RefillMenu,RefillMenu>;
    AccountActions &accountActions = AccountActions::get_instance();
    TokenDto currentToken;
    Ui::RefillMenu *ui;
};

#endif // REFILLMENU_H
