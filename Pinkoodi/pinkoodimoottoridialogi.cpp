#include "pinkoodimoottoridialogi.h"
#include "ui_pinkoodimoottoridialogi.h"

pinkoodiMoottoriDialogi::pinkoodiMoottoriDialogi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinkoodiMoottoriDialogi)
{
    qDebug() << "Moottori luotu";
    ui->setupUi(this);
    ui->lineEditPin->setValidator(new QIntValidator);

}

pinkoodiMoottoriDialogi::~pinkoodiMoottoriDialogi()
{
    delete ui;
}

QString pinkoodiMoottoriDialogi::luePin()
{
    return pinKoodi;
}

void pinkoodiMoottoriDialogi::on_pushButton1_clicked()
{
    ui->lineEditPin->insert("1");
}

void pinkoodiMoottoriDialogi::on_pushButton2_clicked()
{
    ui->lineEditPin->insert("2");
}

void pinkoodiMoottoriDialogi::on_pushButton3_clicked()
{
    ui->lineEditPin->insert("3");
}

void pinkoodiMoottoriDialogi::on_pushButton4_clicked()
{
    ui->lineEditPin->insert("4");
}

void pinkoodiMoottoriDialogi::on_pushButton5_clicked()
{
    ui->lineEditPin->insert("5");
}

void pinkoodiMoottoriDialogi::on_pushButton6_clicked()
{
    ui->lineEditPin->insert("6");
}

void pinkoodiMoottoriDialogi::on_pushButton7_clicked()
{
    ui->lineEditPin->insert("7");
}

void pinkoodiMoottoriDialogi::on_pushButton8_clicked()
{
    ui->lineEditPin->insert("8");
}

void pinkoodiMoottoriDialogi::on_pushButton9_clicked()
{
    ui->lineEditPin->insert("9");
}

void pinkoodiMoottoriDialogi::on_pushButton0_clicked()
{
    ui->lineEditPin->insert("0");
}

void pinkoodiMoottoriDialogi::on_pushButtonC_clicked()
{
    ui->lineEditPin->backspace();
}

void pinkoodiMoottoriDialogi::on_pushButtonOK_clicked()
{
    pinKoodi = ui->lineEditPin->text();
    qDebug() << "Moottorilta palautettiin PIN-koodi: " << pinKoodi;
    this->close();
}



