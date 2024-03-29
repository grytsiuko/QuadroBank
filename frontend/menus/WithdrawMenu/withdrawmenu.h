#ifndef WITHDRAWMENU_H
#define WITHDRAWMENU_H

#include <QWidget>
#include "QRegExpValidator"
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_withdrawmenu.h"
#include "../../actions/account_actions.h"
#include "frontend/menus/utils/token_menu_interface/token_menu_interface.h"

namespace Ui {
class WithdrawMenu;
}

class WithdrawMenu : public QWidget, public Singleton<WithdrawMenu>, TokenInterface
{
    Q_OBJECT

public:
    ~WithdrawMenu();

    void set_token(const SessionDto& token);

public slots:
    void withdraw();
    void clear_inputs();
private:
    explicit WithdrawMenu(QWidget *parent = nullptr) :
        QWidget(parent),
        ui(new Ui::WithdrawMenu)
    {
        ui->setupUi(this);
        connect( ui->withdraw_button,SIGNAL(clicked()),this,SLOT(withdraw()));
        connect( ui->back_button,SIGNAL(clicked()),this,SLOT(clear_inputs()));

        QRegExp re("^[0-9]+(\\.[0-9]{1,2})?$");
        QRegExpValidator *validator = new QRegExpValidator(re, this);
        ui->amount_input->setValidator(validator);
    }
    void update_balance_label();
    friend Singleton;
    friend object_ui<Ui::WithdrawMenu,WithdrawMenu>;
    AccountActions &accountActions = AccountActions::get_instance();
    Ui::WithdrawMenu *ui;
};

#endif // WITHDRAWMENU_H
