#ifndef PINKOODI_H
#define PINKOODI_H

#include <QDebug>
#include "pinkoodi_global.h"
#include "pinkoodimoottoridialogi.h"

class Pinkoodi : public QObject
{
    Q_OBJECT

public:
    explicit PINKOODISHARED_EXPORT Pinkoodi();
    PINKOODISHARED_EXPORT ~Pinkoodi();
    void PINKOODISHARED_EXPORT rajapintafunktioPinkoodi();

private:
    pinkoodiMoottoriDialogi *pinkoodiUi;
    QString PIN;
signals:
     void PINKOODISHARED_EXPORT pinkoodiSignaali(QString pin);
public slots:
    void palautaPinExelle();
};

#endif // PINKOODI_H
