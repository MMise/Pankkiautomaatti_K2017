#include "mainmenu.h"
#include "ui_mainmenu.h"

mainMenu::mainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainMenu)
{
    ui->setupUi(this);
    nostovalikko = new rahannosto;
    saldovalikko = new saldontarkastus;
    tapahtumavalikko = new tilitapahtumat;
    this->setWindowTitle("BankSimul - Päävalikko");
    connect(ui->pushButtonNosto,SIGNAL(clicked(bool)),this,SLOT(naytaNosto()));
    connect(ui->pushButtonSaldo,SIGNAL(clicked(bool)),this,SLOT(naytaSaldo()));
    connect(ui->pushButtonTilitapahtumat,SIGNAL(clicked(bool)),this,SLOT(naytaTapahtumat()));
}

mainMenu::~mainMenu()
{
    delete ui;
}

void mainMenu::naytaNosto()
{
    nostovalikko->show();
}

void mainMenu::naytaSaldo()
{
    saldovalikko->show();
}

void mainMenu::naytaTapahtumat()
{
    tapahtumavalikko->show();
}
