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
    connect(ui->pushButtonNosto, SIGNAL(clicked(bool)),this,SLOT(nostoKlikattiin()));
    //connect(parent,SIGNAL(testi()),this,SLOT());

}

mainMenu::~mainMenu()
{
    delete ui;
}

void mainMenu::setData(const QString &kortinNumero)
{
    korttiID = kortinNumero;
}

void mainMenu::naytaNosto()
{
    nostovalikko->show();
    nostovalikko->setData(korttiID);
}

void mainMenu::naytaSaldo()
{
    saldovalikko->show();
    saldovalikko->setData(korttiID);
}

void mainMenu::naytaTapahtumat()
{
    tapahtumavalikko->show();
    tapahtumavalikko->setData(korttiID);
}

void mainMenu::nostoKlikattiin()
{
    emit nostoSignaali();
}

void mainMenu::on_pushButtonUlos_clicked()
{
    this->close();
}
