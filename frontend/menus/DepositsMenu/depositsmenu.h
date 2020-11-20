#ifndef DEPOSITSMENU_H
#define DEPOSITSMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_depositsmenu.h"
#include "../../actions/deposit_actions.h"
#include "frontend/menus/utils/token_menu_interface/token_menu_interface.h"
namespace Ui {
class DepositsMenu;
}

class DepositsMenu :  public QWidget, public Singleton<DepositsMenu>, TokenInterface
{
    Q_OBJECT

public:
    ~DepositsMenu();
    void set_token(const SessionDto& token);
private:
    explicit DepositsMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::DepositsMenu)
    {
        ui->setupUi(this);

    };

    void update_deposits_list();
    friend Singleton;
    friend object_ui<Ui::DepositsMenu,DepositsMenu>;
    DepositActions &depositActions = DepositActions::get_instance();
    Ui::DepositsMenu *ui;
};

#endif // DEPOSITSMENU_H
