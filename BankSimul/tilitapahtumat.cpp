#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"

tilitapahtumat::tilitapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tilitapahtumat)
{
    ui->setupUi(this);
    this->setWindowTitle("BankSimul - Tilitapahtumat");
}

tilitapahtumat::~tilitapahtumat()
{
    delete ui;
}

void tilitapahtumat::setData(const QString &kortinNumero)
{
    korttiID = kortinNumero;
}

void tilitapahtumat::on_pushButton_clicked()
{
    this->close();
}
