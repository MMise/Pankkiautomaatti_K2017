#include "pinkoodi.h"
#include <QDebug>



void Pinkoodi::rajapintafunktioPinkoodi()
{
    //Tähän se kortinnumero ja syötetty pin ruudulta
    kortti = "0b0030522b";
    annettupin = "1234";
    tarkastaPin();
    qDebug() << pinOk << endl;
}

int Pinkoodi::tarkastaPin()
{
    QSqlQuery pin;
    pin.prepare("SELECT salasana from kortti where id_kortti = :kortti");
    pin.bindValue(":kortti", kortti);
    pin.exec();
    while (pin.next()) {
        salasana = pin.value(0).toString();
    }

    int ch = QString::compare(annettupin,salasana);
    if(ch == 0)
    {
        pinOk = true;
    }
    if (ch != 0) {
        pinOk = false;

    }
    return pinOk;
}
