#include <iostream>
#include <cassert>
#include "demo_credit_scheduler.h"
#include "mainwindow.h"
#include <QApplication>

using std::cout;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    demo_credit_scheduler();
    w.show();
    return a.exec();
}