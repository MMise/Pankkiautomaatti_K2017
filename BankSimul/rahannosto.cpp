#include "rahannosto.h"
#include "ui_rahannosto.h"
#include <QDebug>

rahannosto::rahannosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rahannosto)
{
    ui->setupUi(this);
    ui->lineEditNosto->setValidator(new QIntValidator);
    this->setWindowTitle("BankSimul - Rahan nosto");
}

rahannosto::~rahannosto()
{
    delete ui;
}

/*void rahannosto::asetaSumma()
{
    summa = ui->lineEditNosto->text();
}*/

void rahannosto::on_pushButton1_clicked()
{
    ui->lineEditNosto->insert("1");
}

void rahannosto::on_pushButton2_clicked()
{
    ui->lineEditNosto->insert("2");
}

void rahannosto::on_pushButton3_clicked()
{
    ui->lineEditNosto->insert("3");
}

void rahannosto::on_pushButton4_clicked()
{
    ui->lineEditNosto->insert("4");
}

void rahannosto::on_pushButton5_clicked()
{
    ui->lineEditNosto->insert("5");
}

void rahannosto::on_pushButton6_clicked()
{
    ui->lineEditNosto->insert("6");
}

void rahannosto::on_pushButton7_clicked()
{
    ui->lineEditNosto->insert("7");
}

void rahannosto::on_pushButton8_clicked()
{
    ui->lineEditNosto->insert("8");
}

void rahannosto::on_pushButton9_clicked()
{
    ui->lineEditNosto->insert("9");
}

void rahannosto::on_pushButton0_clicked()
{
    ui->lineEditNosto->insert("0");
}

void rahannosto::on_pushButtonC_clicked()
{
    ui->lineEditNosto->backspace();
}

void rahannosto::on_pushButtonOK_clicked()
{
    summa = ui->lineEditNosto->text();
    nosto = summa.toInt();
    /*
     * Tänne koodia, joka tarkastaa saldon riittävyyden
     *
        */
}

void rahannosto::on_pushButton20_clicked()
{
    nosto = 20;
}

void rahannosto::on_pushButton40_clicked()
{
    nosto = 40;
}

void rahannosto::on_pushButton60_clicked()
{
    nosto = 60;
}

void rahannosto::on_pushButton80_clicked()
{
    nosto = 80;
}

void rahannosto::on_pushButton_clicked()
{
    this->close();
}
