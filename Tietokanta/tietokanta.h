#ifndef TIETOKANTA_H
#define TIETOKANTA_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QString>
#include <QDate>

#include "tietokanta_global.h"

class Tietokanta
{

public:
    bool TIETOKANTASHARED_EXPORT rajapintafunktioTietokanta();
    void TIETOKANTASHARED_EXPORT nosto(int);
    int TIETOKANTASHARED_EXPORT tarkastaSaldo();
    bool TIETOKANTASHARED_EXPORT vastaanotaPin(int pin);
    QString TIETOKANTASHARED_EXPORT tarkastaTapahtumat();
    void TIETOKANTASHARED_EXPORT vastaanotaKortti(QString card);
    TIETOKANTASHARED_EXPORT ~Tietokanta();

private:
    double saldo;
    QString kortti = "0";
    QSqlDatabase db;
    QSqlTableModel model;
    bool pinOk;
    int annettupin;
    int salasana;
    QString tilinumero;
};

#endif // TIETOKANTA_H
