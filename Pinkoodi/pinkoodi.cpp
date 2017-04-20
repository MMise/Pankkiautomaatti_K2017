#include "pinkoodi.h"

void Pinkoodi::rajapintafunktioPinkoodi(QString &palautettavaPin)
{ 
    qDebug() << "Pin: " << palautettavaPin;
    pinkoodiUi = new pinkoodiMoottoriDialogi;
    pinkoodiUi->show();
    pinkoodiUi->exec();
    QString apu = pinkoodiUi->luePin();
    palautettavaPin = apu;
}
