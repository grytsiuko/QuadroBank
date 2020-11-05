/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *withdraw_button;
    QPushButton *transfer_button;
    QPushButton *deposits_button;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *payments_button;
    QPushButton *refill_button;
    QPushButton *end_button;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(14);
        MainMenu->setFont(font);
        horizontalLayoutWidget = new QWidget(MainMenu);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 20, 741, 551));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        withdraw_button = new QPushButton(horizontalLayoutWidget);
        withdraw_button->setObjectName(QString::fromUtf8("withdraw_button"));

        verticalLayout->addWidget(withdraw_button);

        transfer_button = new QPushButton(horizontalLayoutWidget);
        transfer_button->setObjectName(QString::fromUtf8("transfer_button"));

        verticalLayout->addWidget(transfer_button);

        deposits_button = new QPushButton(horizontalLayoutWidget);
        deposits_button->setObjectName(QString::fromUtf8("deposits_button"));

        verticalLayout->addWidget(deposits_button);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        payments_button = new QPushButton(horizontalLayoutWidget);
        payments_button->setObjectName(QString::fromUtf8("payments_button"));

        verticalLayout_2->addWidget(payments_button);

        refill_button = new QPushButton(horizontalLayoutWidget);
        refill_button->setObjectName(QString::fromUtf8("refill_button"));

        verticalLayout_2->addWidget(refill_button);

        end_button = new QPushButton(horizontalLayoutWidget);
        end_button->setObjectName(QString::fromUtf8("end_button"));

        verticalLayout_2->addWidget(end_button);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Form", nullptr));
        withdraw_button->setText(QCoreApplication::translate("MainMenu", "Withdraw", nullptr));
        transfer_button->setText(QCoreApplication::translate("MainMenu", "Transfer", nullptr));
        deposits_button->setText(QCoreApplication::translate("MainMenu", "Deposits", nullptr));
        payments_button->setText(QCoreApplication::translate("MainMenu", "Payments", nullptr));
        refill_button->setText(QCoreApplication::translate("MainMenu", "Refill", nullptr));
        end_button->setText(QCoreApplication::translate("MainMenu", "End session", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
