#include "rfid.h"


Rfid::Rfid()
{
    olioRfidMoottori = new rfidMoottori;
    QObject::connect(olioRfidMoottori, SIGNAL(LueMuisti(QString)), this, SLOT(KorttiLuettu(QString)));
}

Rfid::~Rfid() {
    delete olioRfidMoottori;
    olioRfidMoottori = NULL;
}

void Rfid::KorttiLuettu(QString arg) {
    emit rajapintaLueKortti(arg);
    //qDebug() << "rajapinta signaali";
}
