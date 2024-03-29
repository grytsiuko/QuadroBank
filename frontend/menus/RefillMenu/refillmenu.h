#ifndef REFILLMENU_H
#define REFILLMENU_H

#include <QWidget>
#include "QRegExpValidator"
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_refillmenu.h"
#include "../../actions/account_actions.h"
#include "frontend/menus/utils/token_menu_interface/token_menu_interface.h"
namespace Ui {
class RefillMenu;
}

class RefillMenu : public QWidget, public Singleton<RefillMenu>, TokenInterface
{
    Q_OBJECT

public:
    ~RefillMenu();
    void update_balance_label();
    void set_token(const SessionDto& token);

public slots:
    void refill();
    void clear_inputs();

private:
    explicit RefillMenu(QWidget *parent = nullptr) :
        QWidget(parent),
        ui(new Ui::RefillMenu)
    {
        ui->setupUi(this);
        connect( ui->refill_button,SIGNAL(clicked()),this,SLOT(refill()));
        connect( ui->back_button,SIGNAL(clicked()),this,SLOT(clear_inputs()));


        QRegExp re("^[0-9]+(\\.[0-9]{1,2})?$");
        QRegExpValidator *validator = new QRegExpValidator(re, this);
        ui->amount_input->setValidator(validator);
    }
    friend Singleton;
    friend object_ui<Ui::RefillMenu,RefillMenu>;
    AccountActions &accountActions = AccountActions::get_instance();
    Ui::RefillMenu *ui;
};

#endif // REFILLMENU_H
