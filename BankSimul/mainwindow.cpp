#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSimul");
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_lueKortti->setEnabled(false);

    tietokanta = new Tietokanta;
    tietokanta->rajapintafunktioTietokanta();
    tietokanta->vastaanotaKortti("0b0030522b");

    kortinlukija = new Rfid;
    connect(kortinlukija,SIGNAL(rajapintaLueKortti(QString)),this,SLOT(kortinLukeminen(QString)));

    koodinkysely = new Pinkoodi;
}

MainWindow::~MainWindow()
{
    delete koodinkysely;
    delete tietokanta;
    delete ui;
}

void MainWindow::kortinLukeminen(QString card)
{
    korttiID = card;
    tietokanta->vastaanotaKortti(korttiID);
    qDebug() << korttiID;
    koodinkysely->rajapintafunktioPinkoodi(pinKoodi);
    ui->pushButton_lueKortti->setEnabled(true);
}


void MainWindow::on_pushButton_lueKortti_clicked()
{

    /*PIN = pinKoodi.toInt();
    if(tietokanta->vastaanotaPin(PIN)){
        ui->stackedWidget->setCurrentIndex(1);
    }else{
        qDebug() << "PIN-koodi ei täsmää";
    }*/
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonNosto_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButtonSaldo_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    saldo = tietokanta->tarkastaSaldo();
    saldoNaru = QString::number(saldo);
    ui->labelSaldo_3->setText(saldoNaru);
}

void MainWindow::on_pushButtonTilitapahtumat_2_clicked()
{
    tietokanta->tarkastaTapahtumat();
}

void MainWindow::on_pushButtonUlos_2_clicked()
{
    pinKoodi = "";
    PIN = 0;
    korttiID = "";
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton_lueKortti->setEnabled(false);
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
    if(nosto % 20 == 0 || nosto % 50 == 0){
        tietokanta->nosto(nosto);
        qDebug() << "Nostettiin:" << nosto;
    }else{
        qDebug() << "Et voi nostaa summaa:" << nosto;
    }
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton20_clicked()
{
    nosto = 20;
    tietokanta->nosto(nosto);
    qDebug() << "Nostettiin:" << nosto;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton40_clicked()
{
    nosto = 40;
    tietokanta->nosto(nosto);
    qDebug() << "Nostettiin:" << nosto;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton60_clicked()
{
    nosto = 60;
    tietokanta->nosto(nosto);
    qDebug() << "Nostettiin:" << nosto;
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton80_clicked()
{
    nosto = 80;
    tietokanta->nosto(nosto);
    qDebug() << "Nostettiin:" << nosto;
    ui->stackedWidget->setCurrentIndex(1);
}
