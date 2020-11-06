#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <backend/account/dto/token_dto.h>
#include "../backend/scheduler/scheduler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void set_token_dto(TokenDto const& ttt);
    void set_mainmenu();
    void set_loginmenu();
    void set_transfermenu();
    void set_withdrawmenu();
    void set_refillmenu();
    void set_depositsmenu();
    void set_newdepositsmenu();
    void set_paymentsmenu();
    void set_newpaymentmenu();
    void set_updatepaymentmenu();

private:
    QStackedWidget* menus=nullptr;
    Ui::MainWindow *ui;
    TokenDto currentToken;
//    const Scheduler& scheduler = Scheduler::get_instance();
};
#endif // MAINWINDOW_H
