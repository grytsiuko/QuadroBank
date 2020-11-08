//
// Created by alouh on 08.11.2020.
//
#include "info_message.h"

void showInfo(const QString& info){
    QMessageBox msgBox;
//    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Information");
    msgBox.setInformativeText(info);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setStyleSheet("QLabel{min-width: 150px;}");
    msgBox.exec();
}
