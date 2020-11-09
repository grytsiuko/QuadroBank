#include "demo_deposit_scheduler.h"
#include "demo_regular_payment_scheduler.h"
#include "mainwindow.h"
#include <QApplication>

using std::cout;

int main(int argc, char *argv[]) {
//    Scheduler::get_instance();
    QApplication a(argc, argv);
    MainWindow w;
//    demo_deposit_scheduler();
//    demo_regular_payment_scheduler();
    AccountActions::get_instance();
    w.show();
    return a.exec();
}