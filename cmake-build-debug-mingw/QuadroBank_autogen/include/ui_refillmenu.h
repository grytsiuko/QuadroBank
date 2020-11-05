/********************************************************************************
** Form generated from reading UI file 'refillmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFILLMENU_H
#define UI_REFILLMENU_H

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

class Ui_RefillMenu
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
    QSpacerItem *verticalSpacer;
    QHBoxLayout *ButtonsLayout;
    QPushButton *back_button;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *refill_button;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *RefillMenu)
    {
        if (RefillMenu->objectName().isEmpty())
            RefillMenu->setObjectName(QString::fromUtf8("RefillMenu"));
        RefillMenu->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(14);
        RefillMenu->setFont(font);
        verticalLayoutWidget = new QWidget(RefillMenu);
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
        amount_input->setMaxLength(10);

        AmountLayout->addWidget(amount_input);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        AmountLayout->addItem(horizontalSpacer_4);


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

        refill_button = new QPushButton(verticalLayoutWidget);
        refill_button->setObjectName(QString::fromUtf8("refill_button"));

        ButtonsLayout->addWidget(refill_button);


        MainLayout->addLayout(ButtonsLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        MainLayout->addItem(verticalSpacer_3);


        retranslateUi(RefillMenu);

        QMetaObject::connectSlotsByName(RefillMenu);
    } // setupUi

    void retranslateUi(QWidget *RefillMenu)
    {
        RefillMenu->setWindowTitle(QCoreApplication::translate("RefillMenu", "Form", nullptr));
        LabelName->setText(QCoreApplication::translate("RefillMenu", "Your Balance: 0 $", nullptr));
        amount_input->setInputMask(QString());
        amount_input->setText(QString());
        amount_input->setPlaceholderText(QCoreApplication::translate("RefillMenu", "Enter amount to refill", nullptr));
        back_button->setText(QCoreApplication::translate("RefillMenu", "Back", nullptr));
        refill_button->setText(QCoreApplication::translate("RefillMenu", "Refill", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RefillMenu: public Ui_RefillMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFILLMENU_H
