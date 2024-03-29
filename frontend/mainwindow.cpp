//main includes
#include "mainwindow.h"
#include "./ui_mainwindow.h"
//including menus
#include "menus/LoginMenu/loginmenu.h"
#include "menus/MainMenu/mainmenu.h"
#include "menus/TransferMenu/transfermenu.h"
#include "menus/WithdrawMenu/withdrawmenu.h"
#include "menus/RefillMenu/refillmenu.h"
#include "menus/DepositsMenu/depositsmenu.h"
#include "menus/NewDepositMenu/newdepositmenu.h"
#include "menus/PaymentsMenu/paymentsmenu.h"
#include "menus/NewPaymentMenu/newpaymentmenu.h"
#include "menus/UpdatePaymentMenu/updatepaymentmenu.h"
//QT includes
#include <QStackedWidget>

MainWindow::MainWindow()
        : QMainWindow(), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    menus = new QStackedWidget();
    menus->addWidget(&LoginMenu::get_instance());
    menus->addWidget(&MainMenu::get_instance());
    menus->addWidget(&TransferMenu::get_instance());
    menus->addWidget(&WithdrawMenu::get_instance());
    menus->addWidget(&RefillMenu::get_instance());
    menus->addWidget(&DepositsMenu::get_instance());
    menus->addWidget(&NewDepositMenu::get_instance());
    menus->addWidget(&PaymentsMenu::get_instance());
    menus->addWidget(&NewPaymentMenu::get_instance());
    menus->addWidget(&UpdatePaymentMenu::get_instance());
    setCentralWidget(menus);
    set_loginmenu();
}

MainWindow::~MainWindow() {
    LoginMenu::get_instance().setParent(nullptr);
    MainMenu::get_instance().setParent(nullptr);
    TransferMenu::get_instance().setParent(nullptr);
    WithdrawMenu::get_instance().setParent(nullptr);
    RefillMenu::get_instance().setParent(nullptr);
    DepositsMenu::get_instance().setParent(nullptr);
    NewDepositMenu::get_instance().setParent(nullptr);
    PaymentsMenu::get_instance().setParent(nullptr);
    NewPaymentMenu::get_instance().setParent(nullptr);
    UpdatePaymentMenu::get_instance().setParent(nullptr);
    delete ui;
}

void MainWindow::set_token_dto(SessionDto const &sessionDto) {
    currentSession = sessionDto;
};

void MainWindow::set_mainmenu() {
    // create object ui getter
    object_ui<Ui::MainMenu, MainMenu> mainmenu_ui_getter;
    // retrieve ui object
    Ui::MainMenu *mainmenu_ui = mainmenu_ui_getter.getUi(MainMenu::get_instance());
    // connect buttons to slots
    disconnect(mainmenu_ui->end_button, SIGNAL(clicked()), this, SLOT(set_loginmenu()));
    connect(mainmenu_ui->end_button, SIGNAL(clicked()), this, SLOT(set_loginmenu()));

    disconnect(mainmenu_ui->transfer_button, SIGNAL(clicked()), this, SLOT(set_transfermenu()));
    connect(mainmenu_ui->transfer_button, SIGNAL(clicked()), this, SLOT(set_transfermenu()));

    disconnect(mainmenu_ui->withdraw_button, SIGNAL(clicked()), this, SLOT(set_withdrawmenu()));
    connect(mainmenu_ui->withdraw_button, SIGNAL(clicked()), this, SLOT(set_withdrawmenu()));

    disconnect(mainmenu_ui->refill_button, SIGNAL(clicked()), this, SLOT(set_refillmenu()));
    connect(mainmenu_ui->refill_button, SIGNAL(clicked()), this, SLOT(set_refillmenu()));

    disconnect(mainmenu_ui->deposits_button, SIGNAL(clicked()), this, SLOT(set_depositsmenu()));
    connect(mainmenu_ui->deposits_button, SIGNAL(clicked()), this, SLOT(set_depositsmenu()));

    disconnect(mainmenu_ui->payments_button, SIGNAL(clicked()), this, SLOT(set_paymentsmenu()));
    connect(mainmenu_ui->payments_button, SIGNAL(clicked()), this, SLOT(set_paymentsmenu()));

    MainMenu::get_instance().set_token(currentSession);

    // get index of menu, we need to set, and set it
    menus->setCurrentIndex(menus->indexOf(&MainMenu::get_instance()));
}

void MainWindow::set_loginmenu() {
    disconnect(&LoginMenu::get_instance(), SIGNAL(send_token(SessionDto const&)), this,
               SLOT(set_token_dto(SessionDto const&)));
    connect(&LoginMenu::get_instance(), SIGNAL(send_token(SessionDto const&)), this,
            SLOT(set_token_dto(SessionDto const&)));

    disconnect(&LoginMenu::get_instance(), SIGNAL(input_validated()), this, SLOT(set_mainmenu()));
    connect(&LoginMenu::get_instance(), SIGNAL(input_validated()), this, SLOT(set_mainmenu()));

    // get index of menu, we need to set, and set it
    menus->setCurrentIndex(menus->indexOf(&LoginMenu::get_instance()));
}

void MainWindow::set_transfermenu() {
    // create object ui getter
    object_ui<Ui::TransferMenu, TransferMenu> transfermenu_ui_getter;
    // retrieve ui object
    Ui::TransferMenu *transfermenu_ui = transfermenu_ui_getter.getUi(TransferMenu::get_instance());
    // connect buttons to slots

    disconnect(transfermenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));
    connect(transfermenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));

    TransferMenu::get_instance().set_token(currentSession);
    // get index of menu, we need to set, and set it
    menus->setCurrentIndex(menus->indexOf(&TransferMenu::get_instance()));
}

void MainWindow::set_withdrawmenu() {
    // create object ui getter
    object_ui<Ui::WithdrawMenu, WithdrawMenu> withdrawmenu_ui_getter;
    // retrieve ui object
    Ui::WithdrawMenu *withdrawmenu_ui = withdrawmenu_ui_getter.getUi(WithdrawMenu::get_instance());
    // connect buttons to slots
    disconnect(withdrawmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));
    connect(withdrawmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));
    // pass token to menu
    WithdrawMenu::get_instance().set_token(currentSession);
    // get index of menu, we need to set, and set it
    menus->setCurrentIndex(menus->indexOf(&WithdrawMenu::get_instance()));
}

void MainWindow::set_refillmenu() {
    // create object ui getter
    object_ui<Ui::RefillMenu, RefillMenu> refillmenu_ui_getter;
    // retrieve ui object
    Ui::RefillMenu *refillmenu_ui = refillmenu_ui_getter.getUi(RefillMenu::get_instance());
    // connect buttons to slots

    disconnect(refillmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));
    connect(refillmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));

    RefillMenu::get_instance().set_token(currentSession);

    menus->setCurrentIndex(menus->indexOf(&RefillMenu::get_instance()));
}

void MainWindow::set_depositsmenu() {
    // create object ui getter
    object_ui<Ui::DepositsMenu, DepositsMenu> depositsmenu_ui_getter;
    // retrieve ui object
    Ui::DepositsMenu *depositsmenu_ui = depositsmenu_ui_getter.getUi(DepositsMenu::get_instance());
    // connect buttons to slots

    disconnect(depositsmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));
    connect(depositsmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));

    disconnect(depositsmenu_ui->new_deposit_button, SIGNAL(clicked()), this, SLOT(set_newdepositsmenu()));
    connect(depositsmenu_ui->new_deposit_button, SIGNAL(clicked()), this, SLOT(set_newdepositsmenu()));

    DepositsMenu::get_instance().set_token(currentSession);
    menus->setCurrentIndex(menus->indexOf(&DepositsMenu::get_instance()));
}

void MainWindow::set_newdepositsmenu() {
    // create object ui getter
    object_ui<Ui::NewDepositMenu, NewDepositMenu> newdepositmenu_ui_getter;
    // retrieve ui object
    Ui::NewDepositMenu *newdepositmenu_ui = newdepositmenu_ui_getter.getUi(NewDepositMenu::get_instance());
    // connect buttons to slots

    disconnect(newdepositmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_depositsmenu()));
    connect(newdepositmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_depositsmenu()));


    NewDepositMenu::get_instance().set_token(currentSession);

    // get index of menu, we need to set, and set it
    menus->setCurrentIndex(menus->indexOf(&NewDepositMenu::get_instance()));
}

void MainWindow::set_paymentsmenu() {
    // create object ui getter
    object_ui<Ui::PaymentsMenu, PaymentsMenu> paymentsmenu_ui_getter;
    // retrieve ui object
    Ui::PaymentsMenu *paymentsmenu_ui = paymentsmenu_ui_getter.getUi(PaymentsMenu::get_instance());
    // connect buttons to slots

    disconnect(paymentsmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));
    connect(paymentsmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_mainmenu()));

    disconnect(paymentsmenu_ui->new_payment_button, SIGNAL(clicked()), this, SLOT(set_newpaymentmenu()));
    connect(paymentsmenu_ui->new_payment_button, SIGNAL(clicked()), this, SLOT(set_newpaymentmenu()));

    disconnect(&PaymentsMenu::get_instance(), SIGNAL(go_update()), this,
               SLOT(set_updatepaymentmenu()));
    connect(&PaymentsMenu::get_instance(), SIGNAL(go_update()), this,
               SLOT(set_updatepaymentmenu()));

    disconnect(&PaymentsMenu::get_instance(), SIGNAL(edit_payment(int)),
            &UpdatePaymentMenu::get_instance(), SLOT(update_payment(int)));
    connect(&PaymentsMenu::get_instance(), SIGNAL(edit_payment(int)),
            &UpdatePaymentMenu::get_instance(), SLOT(update_payment(int)));

    PaymentsMenu::get_instance().set_token(currentSession);
    // get index of menu, we need to set, and set it
    menus->setCurrentIndex(menus->indexOf(&PaymentsMenu::get_instance()));
}

void MainWindow::set_newpaymentmenu() {
    // create object ui getter
    object_ui<Ui::NewPaymentMenu, NewPaymentMenu> newpaymentmenu_ui_getter;
    // retrieve ui object
    Ui::NewPaymentMenu *newpaymentmenu_ui = newpaymentmenu_ui_getter.getUi(NewPaymentMenu::get_instance());
    // connect buttons to slots

    disconnect(newpaymentmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_paymentsmenu()));
    connect(newpaymentmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_paymentsmenu()));

    NewPaymentMenu::get_instance().set_token(currentSession);

    // get index of menu, we need to set, and set it
    menus->setCurrentIndex(menus->indexOf(&NewPaymentMenu::get_instance()));
}

void MainWindow::set_updatepaymentmenu(){
    // create object ui getter
    object_ui<Ui::UpdatePaymentMenu, UpdatePaymentMenu> updatepaymentmenu_ui_getter;
    // retrieve ui object
    Ui::UpdatePaymentMenu *updatepaymentmenu_ui = updatepaymentmenu_ui_getter.getUi(UpdatePaymentMenu::get_instance());
    // connect buttons to slots

    disconnect(updatepaymentmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_paymentsmenu()));
    connect(updatepaymentmenu_ui->back_button, SIGNAL(clicked()), this, SLOT(set_paymentsmenu()));

    disconnect(&UpdatePaymentMenu::get_instance(), SIGNAL(updated()), this, SLOT(set_paymentsmenu()));
    connect(&UpdatePaymentMenu::get_instance(), SIGNAL(updated()), this, SLOT(set_paymentsmenu()));


    UpdatePaymentMenu::get_instance().set_token(currentSession);

    // get index of menu, we need to set, and set it
    menus->setCurrentIndex(menus->indexOf(&UpdatePaymentMenu::get_instance()));
};









