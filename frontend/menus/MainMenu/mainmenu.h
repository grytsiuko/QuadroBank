#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "backend/utils/singleton.h"
#include "../utils/object_ui.h"
#include "ui_mainmenu.h"


namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget, public Singleton<MainMenu>
{
    Q_OBJECT

public:
    ~MainMenu();
private:
    MainMenu(QWidget *parent = nullptr):
        QWidget(parent),
        ui(new Ui::MainMenu)
    {
        ui->setupUi(this);
    };;
    friend Singleton;
    friend object_ui<Ui::MainMenu,MainMenu>;
    Ui::MainMenu *ui;

};

#endif // MAINMENU_H
