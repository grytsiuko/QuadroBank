/********************************************************************************
** Form generated from reading UI file 'depositsmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITSMENU_H
#define UI_DEPOSITSMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositsMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *MainLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *DepositsLabel;
    QSpacerItem *verticalSpacer_4;
    QTableView *deposits_table;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *ButtonsLayout;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *new_deposit_button;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *DepositsMenu)
    {
        if (DepositsMenu->objectName().isEmpty())
            DepositsMenu->setObjectName(QString::fromUtf8("DepositsMenu"));
        DepositsMenu->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(14);
        DepositsMenu->setFont(font);
        verticalLayoutWidget = new QWidget(DepositsMenu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 781, 581));
        MainLayout = new QVBoxLayout(verticalLayoutWidget);
        MainLayout->setObjectName(QString::fromUtf8("MainLayout"));
        MainLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_2);

        DepositsLabel = new QLabel(verticalLayoutWidget);
        DepositsLabel->setObjectName(QString::fromUtf8("DepositsLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Playbill"));
        font1.setPointSize(36);
        DepositsLabel->setFont(font1);
        DepositsLabel->setTextFormat(Qt::PlainText);
        DepositsLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        MainLayout->addWidget(DepositsLabel);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_4);

        deposits_table = new QTableView(verticalLayoutWidget);
        deposits_table->setObjectName(QString::fromUtf8("deposits_table"));

        MainLayout->addWidget(deposits_table);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer);

        ButtonsLayout = new QHBoxLayout();
        ButtonsLayout->setObjectName(QString::fromUtf8("ButtonsLayout"));
        back_button = new QPushButton(verticalLayoutWidget);
        back_button->setObjectName(QString::fromUtf8("back_button"));

        ButtonsLayout->addWidget(back_button);

        horizontalSpacer_2 = new QSpacerItem(38, 18, QSizePolicy::Minimum, QSizePolicy::Minimum);

        ButtonsLayout->addItem(horizontalSpacer_2);

        new_deposit_button = new QPushButton(verticalLayoutWidget);
        new_deposit_button->setObjectName(QString::fromUtf8("new_deposit_button"));

        ButtonsLayout->addWidget(new_deposit_button);


        MainLayout->addLayout(ButtonsLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_3);


        retranslateUi(DepositsMenu);

        QMetaObject::connectSlotsByName(DepositsMenu);
    } // setupUi

    void retranslateUi(QWidget *DepositsMenu)
    {
        DepositsMenu->setWindowTitle(QCoreApplication::translate("DepositsMenu", "Form", nullptr));
        DepositsLabel->setText(QCoreApplication::translate("DepositsMenu", "Your Deposits", nullptr));
        back_button->setText(QCoreApplication::translate("DepositsMenu", "Back", nullptr));
        new_deposit_button->setText(QCoreApplication::translate("DepositsMenu", "New Deposit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepositsMenu: public Ui_DepositsMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITSMENU_H
