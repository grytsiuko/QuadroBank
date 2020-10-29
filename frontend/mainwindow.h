#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

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
    void set_mainmenu();
    void set_loginmenu();
    void set_transfermenu();
    void set_withdrawmenu();
    void set_refillmenu();
    void set_depositsmenu();
    void set_newdepositsmenu();
    void set_paymentsmenu();
    void set_newpaymentmenu();

private:
    QStackedWidget* menus=nullptr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
