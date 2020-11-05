#ifndef TRANSFERMENU_H
#define TRANSFERMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_transfermenu.h"
#include "../../actions/account_actions.h"

namespace Ui {
class TransferMenu;
}

class TransferMenu : public QWidget, public Singleton<TransferMenu>
{
    Q_OBJECT

public:
    ~TransferMenu();
    void update_balance_label();
    void set_token(const TokenDto& token);

public slots:
    void transfer();

private:
    explicit TransferMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::TransferMenu)
    {
        ui->setupUi(this);
        connect( ui->transfer_button,SIGNAL(clicked()),this,SLOT(transfer()));
    };
    friend Singleton;
    friend object_ui<Ui::TransferMenu,TransferMenu>;
    AccountActions &accountActions = AccountActions::get_instance();
    TokenDto currentToken;
    Ui::TransferMenu *ui;
};

#endif // TRANSFERMENU_H
