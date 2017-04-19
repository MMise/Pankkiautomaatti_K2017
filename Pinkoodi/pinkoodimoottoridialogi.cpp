#include "pinkoodimoottoridialogi.h"
#include "ui_pinkoodimoottoridialogi.h"

pinkoodiMoottoriDialogi::pinkoodiMoottoriDialogi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pinkoodiMoottoriDialogi)
{
    ui->setupUi(this);
    this->show();
    this->exec();
    ui->lineEditPin->setValidator(new QIntValidator);
    //connect(ui->pushButtonOK,SIGNAL(clicked(bool)),this,SLOT(klikattuOK()));
}

pinkoodiMoottoriDialogi::~pinkoodiMoottoriDialogi()
{
    delete ui;
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
    emit passPin(pinKoodi);
    qDebug() << "Moottorilta palautettiin PIN-koodi: " << pinKoodi;
}

/*void pinkoodiMoottoriDialogi::klikattuOK()
{
    qDebug() << "Pin-koodia palautetaan moottorilta";
    emit passPin(pinKoodi);
}*/



