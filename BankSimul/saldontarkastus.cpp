#include "saldontarkastus.h"
#include "ui_saldontarkastus.h"

saldontarkastus::saldontarkastus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldontarkastus)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSimul - Saldon tarkastus");
}

saldontarkastus::~saldontarkastus()
{
    delete ui;
}

void saldontarkastus::on_pushButton_clicked()
{
    this->close();
}
