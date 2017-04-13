#include "tietokanta.h"
#include <QDebug>
bool Tietokanta::rajapintafunktioTietokanta()
{
    qDebug() << "in fuction rajapintapintafunktio" << endl;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("mysli.oamk.fi");
    db.setDatabaseName("opisk_t6jomi00");
    db.setUserName("t6jomi00");
    db.setPassword("okEyaA8PA6HrAsg6");
    if (!db.open()) {
        qDebug() << "Unable to establish a database connection";
        return false;
    }
    else {
        return true;
    }
}

int Tietokanta::tarkastaSaldo()
{
    qDebug() << "in function tarkastaSaldo" << endl;
    QSqlQuery query;
    query.prepare("SELECT saldo from tili where id_kortti = :kortti");
    query.bindValue(":kortti", kortti);
    query.exec();
    while (query.next()) {
        saldo = query.value(0).toDouble();
    }
    qDebug() << saldo << endl;
    return saldo;
}

Tietokanta::~Tietokanta()
{
    db.close();
}

void Tietokanta::nosto(int c)
{
    int maara;
    maara = c;
    QSqlQuery query;
    query.prepare("SELECT saldo from tili where id_kortti = :kortti");
    query.bindValue(":kortti", kortti);
    query.exec();
    while (query.next()) {
        saldo = query.value(0).toDouble();
    }
    qDebug() << saldo << endl;
    if(c < saldo) {
        saldo = saldo - c;
        query.prepare("UPDATE tili SET saldo = :saldo where id_kortti = :kortti");
        query.bindValue(":saldo", saldo);
        query.bindValue(":kortti", kortti);
        query.exec();
        QSqlTableModel model;
        model.setTable("tapahtuma");
        int row = 0;
        model.insertRows(row,1);
        model.setData(model.index(row, 1), kortti);
        model.setData(model.index(row, 3), "NOSTO");
        model.setData(model.index(row, 4), maara);
        model.submitAll();
    }
    else {
        qDebug() << "Saldo ei riita" << endl;
    }
}

int Tietokanta::tarkastaPin()
{
    annettupin = "1234";
    QSqlQuery pin;
    pin.prepare("SELECT salasana from kortti where id_kortti = :kortti");
    pin.bindValue(":kortti", kortti);
    pin.exec();
    while (pin.next()) {
        salasana = pin.value(0).toString();
    }

    int ch = QString::compare(annettupin,salasana);
    if(ch == 0)
    {
        pinOk = true;
    }
    if (ch != 0) {
        pinOk = false;

    }
    return pinOk;
}

