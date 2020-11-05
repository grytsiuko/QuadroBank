/********************************************************************************
** Form generated from reading UI file 'newdepositmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDEPOSITMENU_H
#define UI_NEWDEPOSITMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewDepositMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *MainLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *LabelName;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *InputLayout;
    QHBoxLayout *AmountLayout;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *amount_input;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *DateLayout;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *ButtonsLayout;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *new_deposit_button;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *NewDepositMenu)
    {
        if (NewDepositMenu->objectName().isEmpty())
            NewDepositMenu->setObjectName(QString::fromUtf8("NewDepositMenu"));
        NewDepositMenu->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(14);
        NewDepositMenu->setFont(font);
        verticalLayoutWidget = new QWidget(NewDepositMenu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 781, 581));
        MainLayout = new QVBoxLayout(verticalLayoutWidget);
        MainLayout->setObjectName(QString::fromUtf8("MainLayout"));
        MainLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_2);

        LabelName = new QLabel(verticalLayoutWidget);
        LabelName->setObjectName(QString::fromUtf8("LabelName"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Playbill"));
        font1.setPointSize(36);
        LabelName->setFont(font1);
        LabelName->setTextFormat(Qt::PlainText);
        LabelName->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        MainLayout->addWidget(LabelName);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_4);

        InputLayout = new QVBoxLayout();
        InputLayout->setObjectName(QString::fromUtf8("InputLayout"));
        AmountLayout = new QHBoxLayout();
        AmountLayout->setObjectName(QString::fromUtf8("AmountLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AmountLayout->addItem(horizontalSpacer_3);

        amount_input = new QLineEdit(verticalLayoutWidget);
        amount_input->setObjectName(QString::fromUtf8("amount_input"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(amount_input->sizePolicy().hasHeightForWidth());
        amount_input->setSizePolicy(sizePolicy);
        amount_input->setMinimumSize(QSize(400, 40));
        amount_input->setFont(font);
        amount_input->setMaxLength(16);

        AmountLayout->addWidget(amount_input);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AmountLayout->addItem(horizontalSpacer_4);


        InputLayout->addLayout(AmountLayout);

        DateLayout = new QHBoxLayout();
        DateLayout->setObjectName(QString::fromUtf8("DateLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        DateLayout->addItem(horizontalSpacer_5);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(400, 40));

        DateLayout->addWidget(comboBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        DateLayout->addItem(horizontalSpacer_6);


        InputLayout->addLayout(DateLayout);


        MainLayout->addLayout(InputLayout);

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


        retranslateUi(NewDepositMenu);

        QMetaObject::connectSlotsByName(NewDepositMenu);
    } // setupUi

    void retranslateUi(QWidget *NewDepositMenu)
    {
        NewDepositMenu->setWindowTitle(QCoreApplication::translate("NewDepositMenu", "Form", nullptr));
        LabelName->setText(QCoreApplication::translate("NewDepositMenu", "Your Balance: 0 $", nullptr));
        amount_input->setInputMask(QString());
        amount_input->setText(QString());
        amount_input->setPlaceholderText(QCoreApplication::translate("NewDepositMenu", "Enter amount to deposit", nullptr));
        back_button->setText(QCoreApplication::translate("NewDepositMenu", "Back", nullptr));
        new_deposit_button->setText(QCoreApplication::translate("NewDepositMenu", "Deposit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewDepositMenu: public Ui_NewDepositMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDEPOSITMENU_H
