#ifndef RFID_H
#define RFID_H

#include "rfid_global.h"
#include "rfidmoottori.h"

class Rfid : public QObject
{
    Q_OBJECT

public:
    explicit RFIDSHARED_EXPORT Rfid();
    RFIDSHARED_EXPORT ~Rfid();
public slots:
    void KorttiLuettu(QString arg);
signals:
    void RFIDSHARED_EXPORT rajapintaLueKortti(QString arg);
private:
    rfidMoottori *olioRfidMoottori;
};

#endif // RFID_H
