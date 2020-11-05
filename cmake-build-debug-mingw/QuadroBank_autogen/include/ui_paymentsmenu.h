/********************************************************************************
** Form generated from reading UI file 'paymentsmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTSMENU_H
#define UI_PAYMENTSMENU_H

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

class Ui_PaymentsMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *MainLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *PaymentsLabel;
    QSpacerItem *verticalSpacer_4;
    QTableView *payments_table;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *ButtonsLayout;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *new_payment_button;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *PaymentsMenu)
    {
        if (PaymentsMenu->objectName().isEmpty())
            PaymentsMenu->setObjectName(QString::fromUtf8("PaymentsMenu"));
        PaymentsMenu->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(14);
        PaymentsMenu->setFont(font);
        verticalLayoutWidget = new QWidget(PaymentsMenu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 781, 581));
        MainLayout = new QVBoxLayout(verticalLayoutWidget);
        MainLayout->setObjectName(QString::fromUtf8("MainLayout"));
        MainLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_2);

        PaymentsLabel = new QLabel(verticalLayoutWidget);
        PaymentsLabel->setObjectName(QString::fromUtf8("PaymentsLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Playbill"));
        font1.setPointSize(36);
        PaymentsLabel->setFont(font1);
        PaymentsLabel->setTextFormat(Qt::PlainText);
        PaymentsLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        MainLayout->addWidget(PaymentsLabel);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_4);

        payments_table = new QTableView(verticalLayoutWidget);
        payments_table->setObjectName(QString::fromUtf8("payments_table"));

        MainLayout->addWidget(payments_table);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer);

        ButtonsLayout = new QHBoxLayout();
        ButtonsLayout->setObjectName(QString::fromUtf8("ButtonsLayout"));
        back_button = new QPushButton(verticalLayoutWidget);
        back_button->setObjectName(QString::fromUtf8("back_button"));

        ButtonsLayout->addWidget(back_button);

        horizontalSpacer_2 = new QSpacerItem(38, 18, QSizePolicy::Minimum, QSizePolicy::Minimum);

        ButtonsLayout->addItem(horizontalSpacer_2);

        new_payment_button = new QPushButton(verticalLayoutWidget);
        new_payment_button->setObjectName(QString::fromUtf8("new_payment_button"));

        ButtonsLayout->addWidget(new_payment_button);


        MainLayout->addLayout(ButtonsLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_3);


        retranslateUi(PaymentsMenu);

        QMetaObject::connectSlotsByName(PaymentsMenu);
    } // setupUi

    void retranslateUi(QWidget *PaymentsMenu)
    {
        PaymentsMenu->setWindowTitle(QCoreApplication::translate("PaymentsMenu", "Form", nullptr));
        PaymentsLabel->setText(QCoreApplication::translate("PaymentsMenu", "Your Payments", nullptr));
        back_button->setText(QCoreApplication::translate("PaymentsMenu", "Back", nullptr));
        new_payment_button->setText(QCoreApplication::translate("PaymentsMenu", "New Payment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaymentsMenu: public Ui_PaymentsMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTSMENU_H
