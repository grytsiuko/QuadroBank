/********************************************************************************
** Form generated from reading UI file 'transfermenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERMENU_H
#define UI_TRANSFERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *MainLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *LabelName;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *InputLayout;
    QHBoxLayout *CardLayout;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *card_number_input;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *AmountLayout;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *amount_input;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *ButtonsLayout;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *transfer_button;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *TransferMenu)
    {
        if (TransferMenu->objectName().isEmpty())
            TransferMenu->setObjectName(QString::fromUtf8("TransferMenu"));
        TransferMenu->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(14);
        TransferMenu->setFont(font);
        verticalLayoutWidget = new QWidget(TransferMenu);
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
        CardLayout = new QHBoxLayout();
        CardLayout->setObjectName(QString::fromUtf8("CardLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        CardLayout->addItem(horizontalSpacer_3);

        card_number_input = new QLineEdit(verticalLayoutWidget);
        card_number_input->setObjectName(QString::fromUtf8("card_number_input"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(card_number_input->sizePolicy().hasHeightForWidth());
        card_number_input->setSizePolicy(sizePolicy);
        card_number_input->setMinimumSize(QSize(400, 40));
        card_number_input->setFont(font);
        card_number_input->setMaxLength(16);

        CardLayout->addWidget(card_number_input);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        CardLayout->addItem(horizontalSpacer_4);


        InputLayout->addLayout(CardLayout);

        AmountLayout = new QHBoxLayout();
        AmountLayout->setObjectName(QString::fromUtf8("AmountLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AmountLayout->addItem(horizontalSpacer_5);

        amount_input = new QLineEdit(verticalLayoutWidget);
        amount_input->setObjectName(QString::fromUtf8("amount_input"));
        sizePolicy.setHeightForWidth(amount_input->sizePolicy().hasHeightForWidth());
        amount_input->setSizePolicy(sizePolicy);
        amount_input->setMinimumSize(QSize(400, 40));
        amount_input->setFont(font);
        amount_input->setMaxLength(5);
        amount_input->setEchoMode(QLineEdit::Normal);

        AmountLayout->addWidget(amount_input);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AmountLayout->addItem(horizontalSpacer_6);


        InputLayout->addLayout(AmountLayout);


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

        transfer_button = new QPushButton(verticalLayoutWidget);
        transfer_button->setObjectName(QString::fromUtf8("transfer_button"));

        ButtonsLayout->addWidget(transfer_button);


        MainLayout->addLayout(ButtonsLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_3);


        retranslateUi(TransferMenu);

        QMetaObject::connectSlotsByName(TransferMenu);
    } // setupUi

    void retranslateUi(QWidget *TransferMenu)
    {
        TransferMenu->setWindowTitle(QCoreApplication::translate("TransferMenu", "Form", nullptr));
        LabelName->setText(QCoreApplication::translate("TransferMenu", "Your Balance: 0 $", nullptr));
        card_number_input->setInputMask(QString());
        card_number_input->setText(QString());
        card_number_input->setPlaceholderText(QCoreApplication::translate("TransferMenu", "Enter destination card", nullptr));
        amount_input->setText(QString());
        amount_input->setPlaceholderText(QCoreApplication::translate("TransferMenu", "Enter amount to transfer", nullptr));
        back_button->setText(QCoreApplication::translate("TransferMenu", "Back", nullptr));
        transfer_button->setText(QCoreApplication::translate("TransferMenu", "Transfer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferMenu: public Ui_TransferMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERMENU_H
