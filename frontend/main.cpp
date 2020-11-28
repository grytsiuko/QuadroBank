#include "demo_deposit_scheduler.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    Scheduler::get_instance();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
