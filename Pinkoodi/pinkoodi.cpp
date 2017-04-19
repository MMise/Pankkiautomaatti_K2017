#include "pinkoodi.h"


Pinkoodi::Pinkoodi()
{   

}

Pinkoodi::~Pinkoodi()
{
    delete pinkoodiUi;
    pinkoodiUi = NULL;
}

QString Pinkoodi::rajapintafunktioPinkoodi()
{ 
    pinkoodiUi = new pinkoodiMoottoriDialogi(this);
    connect(pinkoodiUi, SIGNAL(passPin(QString)), this, SLOT(palautaPinExelle()));
}

void Pinkoodi::palautaPinExelle()
{
    qDebug() << "PIN-koodia palautetaan Exelle";
    emit pinkoodiSignaali(PIN);
}
