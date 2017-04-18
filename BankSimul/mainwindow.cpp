#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    paavalikko = new mainMenu;
    //tietokanta = new Tietokanta;
    //tietokanta->rajapintafunktioTietokanta();
    this->setWindowTitle("BankSimul - Aloita");
    koodinkysely = new Pinkoodi;
    connect(ui->pushButton_lueKortti,SIGNAL(clicked(bool)),this,SLOT(naytaValikko()));
    connect(koodinkysely,SIGNAL(pinkoodiSignaali(QString)),this,SLOT(setPin(QString)));
}

MainWindow::~MainWindow()
{
    delete koodinkysely;
    delete ui;
}

void MainWindow::naytaValikko()
{
    //paavalikko->show();
    //paavalikko->setData(korttiID);
    koodinkysely->rajapintafunktioPinkoodi();
    this->close();
}

void MainWindow::setPin(QString str)
{
    qDebug() << "Päästiin PIN-koodin asetukseen";
    PIN = str.toInt();
    qDebug() << PIN;
}


void MainWindow::on_pushButtonTESTI_clicked()
{
    qDebug() << PIN;
}
