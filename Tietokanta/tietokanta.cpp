#include "tietokanta.h"
#include <QDebug>
bool Tietokanta::rajapintafunktioTietokanta()
{
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

void Tietokanta::vastaanotaKortti(QString card)
{
    kortti = card;
    QSqlQuery query;
    query.prepare("SELECT tilinumero from tili where id_kortti = :kortti");
    query.bindValue(":kortti", kortti);
    query.exec();
    while (query.next()) {
        tilinumero = query.value(0).toString();
    }

}

int Tietokanta::tarkastaSaldo()
{
    QSqlQuery query;
    query.prepare("SELECT saldo from tili where tilinumero = :tilinumero");
    query.bindValue(":tilinumero", tilinumero);
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
    query.prepare("SELECT saldo from tili where tilinumero = :tilinumero");
    query.bindValue(":tilinumero", tilinumero);
    query.exec();
    while (query.next()) {
        saldo = query.value(0).toDouble();
    }
    qDebug() << "Query OK @nosto";
    if(c < saldo) {
        saldo = saldo - c;
        query.prepare("UPDATE tili SET saldo = :saldo where tilinumero = :tilinumero");
        query.bindValue(":saldo", saldo);
        query.bindValue(":tilinumero", tilinumero);
        query.exec();
        model.setTable("tapahtuma");
        int row = 0;
        model.insertRows(row,1);
        model.setData(model.index(row, 1), tilinumero);
        model.setData(model.index(row, 3), "NOSTO");
        model.setData(model.index(row, 4), maara);
        model.submitAll();
    }
    else {
        qDebug() << "Saldo ei riita" << endl;
    }
}

bool Tietokanta::vastaanotaPin(int pin)
{
    annettupin = pin;
    QSqlQuery pinkysy;
    pinkysy.prepare("SELECT salasana from kortti where id_kortti = :kortti");
    pinkysy.bindValue(":kortti", kortti);
    pinkysy.exec();
    while (pinkysy.next()) {
        salasana = pinkysy.value(0).toString();
    }

    int ch = QString::compare(annettupin,salasana);
    if(ch == 0){
        pinOk = true;
    }
    if (ch != 0) {
        pinOk = false;
    }
    return pinOk;
}

QString Tietokanta::tarkastaTapahtumat()
{
    QSqlRecord record;
    QDate aika;
    QString paiva, tapahtuma, maara;
    QSqlTableModel *model = new QSqlTableModel;
    QString status = QString("tilinumero = '%1'").arg(tilinumero);
    model->setTable("tapahtuma");
    model->setFilter(status);
    model->select();
    int rivi = model->rowCount();
    for (int i = 0; rivi > i; i++) {
        record = model->record(i);
        aika = record.value("aika").toDate();
        paiva = aika.toString("dd.MM.yyyy");
        tapahtuma = record.value("tapahtuma").toString();
        maara = record.value(4).toString();
        qDebug() << paiva << tapahtuma << maara << "e" << endl;

    }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("PVM"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Tapahtuma"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Määrä"));
    //return *model;
}

