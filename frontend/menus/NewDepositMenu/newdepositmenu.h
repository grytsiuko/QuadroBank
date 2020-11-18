#ifndef NEWDEPOSITMENU_H
#define NEWDEPOSITMENU_H

#include <QWidget>
#include <QtWidgets/QStyledItemDelegate>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_newdepositmenu.h"
#include "../../actions/deposit_actions.h"
#include "../../actions/account_actions.h"
#include "frontend/menus/utils/token_menu_interface/token_menu_interface.h"

namespace Ui {
class NewDepositMenu;
}

class NewDepositMenu :  public QWidget, public Singleton<NewDepositMenu>, TokenInterface
{
    Q_OBJECT

public:
    ~NewDepositMenu();
    void set_token(const TokenDto& token);
private slots:
    void create_deposit();
private:
    explicit NewDepositMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::NewDepositMenu)
    {
        ui->setupUi(this);
        disconnect( ui->new_deposit_button,SIGNAL(clicked()),this,SLOT(create_deposit()));
        connect( ui->new_deposit_button,SIGNAL(clicked()),this,SLOT(create_deposit()));
        ui->comboBox->setItemDelegate(new QStyledItemDelegate(ui->comboBox));
        QRegExp re("^[0-9]+(\\.[0-9]{1,2})?$");
        QRegExpValidator *validator = new QRegExpValidator(re, this);
        ui->amount_input->setValidator(validator);

    };

    void load_deposit_variants();
    void update_balance_label();

    friend Singleton;
    friend object_ui<Ui::NewDepositMenu,NewDepositMenu>;

    DepositActions &depositActions = DepositActions::get_instance();
    AccountActions &accountActions = AccountActions::get_instance();
    Ui::NewDepositMenu *ui;
};

#endif // NEWDEPOSITMENU_H
