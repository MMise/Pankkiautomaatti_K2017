#ifndef PINKOODI_H
#define PINKOODI_H

#include "pinkoodi_global.h"
#include "pinkoodimoottoridialogi.h"

class Pinkoodi
{

public:
    //Pinkoodi();
    void PINKOODISHARED_EXPORT rajapintafunktioPinkoodi();
    int palautaPinExelle();
    void pyydaPin(); //pyytää pinkoodimoottoridialogilta PIN-koodin.
private:
    pinkoodiMoottoriDialogi *pinkoodiUi;
    int PIN;
};

#endif // PINKOODI_H
