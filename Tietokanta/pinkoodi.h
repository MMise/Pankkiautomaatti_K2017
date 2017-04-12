#ifndef PINKOODI_H
#define PINKOODI_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QString>

#include "pinkoodi_global.h"

class Pinkoodi
{

public:
    void PINKOODISHARED_EXPORT rajapintafunktioPinkoodi();
    static bool createConnection()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("mysli.oamk.fi");
        db.setDatabaseName("opisk_t6jomi00");
        db.setUserName("");
        db.setPassword("");
        if (!db.open()) {
            qDebug() << "Unable to establish a database connection";
            return false;
        }
        else {
            return true;
        }
    }
private:
    int tarkastaPin();
    bool pinOk;
    QString annettupin;
    QString salasana;
    QString kortti;
};

#endif // PINKOODI_H
