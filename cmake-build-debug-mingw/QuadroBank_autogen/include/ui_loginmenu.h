/********************************************************************************
** Form generated from reading UI file 'loginmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINMENU_H
#define UI_LOGINMENU_H

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

class Ui_LoginMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *LabelName;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *InputLayout;
    QHBoxLayout *CardLayout;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *card_number_input;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *PasswordLayout;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *password_input;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *EnterButtonLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *enter_button;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *LoginMenu)
    {
        if (LoginMenu->objectName().isEmpty())
            LoginMenu->setObjectName(QString::fromUtf8("LoginMenu"));
        LoginMenu->resize(800, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        LoginMenu->setFont(font);
        verticalLayoutWidget = new QWidget(LoginMenu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 781, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        LabelName = new QLabel(verticalLayoutWidget);
        LabelName->setObjectName(QString::fromUtf8("LabelName"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Playbill"));
        font1.setPointSize(96);
        LabelName->setFont(font1);
        LabelName->setTextFormat(Qt::PlainText);
        LabelName->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout->addWidget(LabelName);

        verticalSpacer = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

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
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(14);
        card_number_input->setFont(font2);
        card_number_input->setMaxLength(16);

        CardLayout->addWidget(card_number_input);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        CardLayout->addItem(horizontalSpacer_4);


        InputLayout->addLayout(CardLayout);

        PasswordLayout = new QHBoxLayout();
        PasswordLayout->setObjectName(QString::fromUtf8("PasswordLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PasswordLayout->addItem(horizontalSpacer_5);

        password_input = new QLineEdit(verticalLayoutWidget);
        password_input->setObjectName(QString::fromUtf8("password_input"));
        sizePolicy.setHeightForWidth(password_input->sizePolicy().hasHeightForWidth());
        password_input->setSizePolicy(sizePolicy);
        password_input->setMinimumSize(QSize(400, 40));
        password_input->setFont(font2);
        password_input->setMaxLength(4);
        password_input->setEchoMode(QLineEdit::Password);

        PasswordLayout->addWidget(password_input);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        PasswordLayout->addItem(horizontalSpacer_6);


        InputLayout->addLayout(PasswordLayout);


        verticalLayout->addLayout(InputLayout);

        EnterButtonLayout = new QHBoxLayout();
        EnterButtonLayout->setObjectName(QString::fromUtf8("EnterButtonLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        EnterButtonLayout->addItem(horizontalSpacer);

        enter_button = new QPushButton(verticalLayoutWidget);
        enter_button->setObjectName(QString::fromUtf8("enter_button"));
        sizePolicy.setHeightForWidth(enter_button->sizePolicy().hasHeightForWidth());
        enter_button->setSizePolicy(sizePolicy);
        enter_button->setMinimumSize(QSize(160, 35));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Comic Sans MS"));
        font3.setPointSize(12);
        enter_button->setFont(font3);

        EnterButtonLayout->addWidget(enter_button);

        horizontalSpacer_2 = new QSpacerItem(38, 18, QSizePolicy::Minimum, QSizePolicy::Minimum);

        EnterButtonLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(EnterButtonLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(LoginMenu);

        QMetaObject::connectSlotsByName(LoginMenu);
    } // setupUi

    void retranslateUi(QWidget *LoginMenu)
    {
        LoginMenu->setWindowTitle(QCoreApplication::translate("LoginMenu", "Form", nullptr));
        LabelName->setText(QCoreApplication::translate("LoginMenu", "QuadroBank", nullptr));
        card_number_input->setInputMask(QString());
        card_number_input->setText(QString());
        card_number_input->setPlaceholderText(QCoreApplication::translate("LoginMenu", "Input your card number", nullptr));
        password_input->setPlaceholderText(QCoreApplication::translate("LoginMenu", "Input your pin code", nullptr));
        enter_button->setText(QCoreApplication::translate("LoginMenu", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginMenu: public Ui_LoginMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINMENU_H
