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
    int TIETOKANTASHARED_EXPORT tarkastaPin();
    QString TIETOKANTASHARED_EXPORT tarkastaTapahtumat();
    void TIETOKANTASHARED_EXPORT vastaanotaKortti(QString card);
    ~Tietokanta();

private:
    double saldo;
    QString kortti = "0";
    QSqlDatabase db;
    QSqlTableModel model;
    bool pinOk;
    QString annettupin;
    QString salasana;
};

#endif // TIETOKANTA_H
