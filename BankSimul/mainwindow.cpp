#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //tietokanta = new Tietokanta;
    //tietokanta->rajapintafunktioTietokanta();
    this->setWindowTitle("BankSimul - Aloita");
    ui->stackedWidget->setCurrentIndex(0);
    koodinkysely = new Pinkoodi;
    //connect(ui->pushButton_lueKortti,SIGNAL(clicked(bool)),this,SLOT(naytaValikko()));
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


void MainWindow::on_pushButton_lueKortti_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    /*
     * Tänne koodia, jossa luetaan kortti
     * ja jos kortti löytyy tietokannasta,
     * näytetään PIN-koodin kysely.
     * Jos PIN-koodi on OK, suoritetaan yllä oleva rivi
     * */
}

void MainWindow::on_pushButtonNosto_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButtonSaldo_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButtonTilitapahtumat_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButtonUlos_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonPeruuta_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonPeruutaSaldo_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonOkTilitapahtumat_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton1_clicked()
{
    ui->lineEditNosto->insert("1");
}

void MainWindow::on_pushButton2_clicked()
{
    ui->lineEditNosto->insert("2");
}

void MainWindow::on_pushButton3_clicked()
{
    ui->lineEditNosto->insert("3");
}

void MainWindow::on_pushButton4_clicked()
{
    ui->lineEditNosto->insert("4");
}

void MainWindow::on_pushButton5_clicked()
{
    ui->lineEditNosto->insert("5");
}

void MainWindow::on_pushButton6_clicked()
{
    ui->lineEditNosto->insert("6");
}

void MainWindow::on_pushButton7_clicked()
{
    ui->lineEditNosto->insert("7");
}

void MainWindow::on_pushButton8_clicked()
{
    ui->lineEditNosto->insert("8");
}

void MainWindow::on_pushButton9_clicked()
{
    ui->lineEditNosto->insert("9");
}

void MainWindow::on_pushButton0_clicked()
{
    ui->lineEditNosto->insert("0");
}

void MainWindow::on_pushButtonC_clicked()
{
    ui->lineEditNosto->backspace();
}

void MainWindow::on_pushButtonOK_clicked()
{
    summa = ui->lineEditNosto->text();
    nosto = summa.toInt();
    /*
     * Tänne koodia, joka tarkastaa saldon riittävyyden
     *
        */
}

void MainWindow::on_pushButton20_clicked()
{
    nosto = 20;
}

void MainWindow::on_pushButton40_clicked()
{
    nosto = 40;
}

void MainWindow::on_pushButton60_clicked()
{
    nosto = 60;
}

void MainWindow::on_pushButton80_clicked()
{
    nosto = 80;
}
