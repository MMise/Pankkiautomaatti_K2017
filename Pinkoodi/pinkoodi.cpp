#include "pinkoodi.h"

void Pinkoodi::rajapintafunktioPinkoodi(QString &palautettavaPin)
{ 

    pinkoodiUi = new pinkoodiMoottoriDialogi;
    pinkoodiUi->show();
    pinkoodiUi->exec();
    QString apu = pinkoodiUi->luePin();
    palautettavaPin = apu;
}
