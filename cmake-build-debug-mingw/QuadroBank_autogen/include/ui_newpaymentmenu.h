/********************************************************************************
** Form generated from reading UI file 'newpaymentmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPAYMENTMENU_H
#define UI_NEWPAYMENTMENU_H

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

class Ui_NewPaymentMenu
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
    QHBoxLayout *DestinationLayout;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *card_input;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *DateLayout;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *ButtonsLayout;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *new_payment_button;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *NewPaymentMenu)
    {
        if (NewPaymentMenu->objectName().isEmpty())
            NewPaymentMenu->setObjectName(QString::fromUtf8("NewPaymentMenu"));
        NewPaymentMenu->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(14);
        NewPaymentMenu->setFont(font);
        verticalLayoutWidget = new QWidget(NewPaymentMenu);
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

        DestinationLayout = new QHBoxLayout();
        DestinationLayout->setObjectName(QString::fromUtf8("DestinationLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        DestinationLayout->addItem(horizontalSpacer_7);

        card_input = new QLineEdit(verticalLayoutWidget);
        card_input->setObjectName(QString::fromUtf8("card_input"));
        sizePolicy.setHeightForWidth(card_input->sizePolicy().hasHeightForWidth());
        card_input->setSizePolicy(sizePolicy);
        card_input->setMinimumSize(QSize(400, 40));
        card_input->setFont(font);
        card_input->setMaxLength(16);

        DestinationLayout->addWidget(card_input);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        DestinationLayout->addItem(horizontalSpacer_8);


        InputLayout->addLayout(DestinationLayout);


        MainLayout->addLayout(InputLayout);

        DateLayout = new QHBoxLayout();
        DateLayout->setObjectName(QString::fromUtf8("DateLayout"));
        horizontalSpacer_5 = new QSpacerItem(190, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        DateLayout->addItem(horizontalSpacer_5);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(280, 40));

        DateLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        DateLayout->addItem(horizontalSpacer);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(100, 40));

        DateLayout->addWidget(comboBox);

        horizontalSpacer_6 = new QSpacerItem(190, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        DateLayout->addItem(horizontalSpacer_6);


        MainLayout->addLayout(DateLayout);

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


        retranslateUi(NewPaymentMenu);

        QMetaObject::connectSlotsByName(NewPaymentMenu);
    } // setupUi

    void retranslateUi(QWidget *NewPaymentMenu)
    {
        NewPaymentMenu->setWindowTitle(QCoreApplication::translate("NewPaymentMenu", "Form", nullptr));
        LabelName->setText(QCoreApplication::translate("NewPaymentMenu", "Your Balance: 0 $", nullptr));
        amount_input->setInputMask(QString());
        amount_input->setText(QString());
        amount_input->setPlaceholderText(QCoreApplication::translate("NewPaymentMenu", "Enter amount to pay", nullptr));
        card_input->setInputMask(QString());
        card_input->setText(QString());
        card_input->setPlaceholderText(QCoreApplication::translate("NewPaymentMenu", "Enter destination card", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("NewPaymentMenu", "Enter quantity", nullptr));
        back_button->setText(QCoreApplication::translate("NewPaymentMenu", "Back", nullptr));
        new_payment_button->setText(QCoreApplication::translate("NewPaymentMenu", "Payment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewPaymentMenu: public Ui_NewPaymentMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPAYMENTMENU_H
