#ifndef TIETOKANTA_H
#define TIETOKANTA_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>

#include "tietokanta_global.h"

class Tietokanta
{

public:
    bool TIETOKANTASHARED_EXPORT rajapintafunktioTietokanta();
    int TIETOKANTASHARED_EXPORT nosto(int);
    int TIETOKANTASHARED_EXPORT tarkastaSaldo();
    int TIETOKANTASHARED_EXPORT tarkastaPin();
    ~Tietokanta();

private:
    int tarkastaTapahtumat();
    double saldo;
    QString kortti = "0b0030522b";
    QString perse;
    QSqlDatabase db;
    bool pinOk;
    QString annettupin;
    QString salasana;
};

#endif // TIETOKANTA_H
