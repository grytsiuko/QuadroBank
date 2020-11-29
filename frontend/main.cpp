#include "demo_deposit_scheduler.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    Scheduler::get_instance();
    w.show();
    a.exec();
    return 0;
}
