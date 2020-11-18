#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_mainmenu.h"
#include "../../actions/account_actions.h"
#include "../utils/token_menu_interface.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget, public Singleton<MainMenu>, TokenInterface
{
    Q_OBJECT

public:
    ~MainMenu();
public slots:
    void set_token(const TokenDto& token);
    void update_balance_label();
private:
    MainMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::MainMenu)
    {
        ui->setupUi(this);
        connect(ui->refresh_button, SIGNAL(clicked()), this, SLOT(update_balance_label()));
    };;

    friend Singleton;
    friend object_ui<Ui::MainMenu,MainMenu>;
    AccountActions &accountActions = AccountActions::get_instance();

    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
