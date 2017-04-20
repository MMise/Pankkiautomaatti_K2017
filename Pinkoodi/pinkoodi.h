#ifndef PINKOODI_H
#define PINKOODI_H

#include <QDebug>
#include <QString>
#include "pinkoodi_global.h"
#include "pinkoodimoottoridialogi.h"

class Pinkoodi
{

public:

    void PINKOODISHARED_EXPORT rajapintafunktioPinkoodi(QString &palautettavaPin);

private:
    pinkoodiMoottoriDialogi *pinkoodiUi;
    QString PIN;

};

#endif // PINKOODI_H
