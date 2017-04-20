#include "tietokanta.h"
#include <QDebug>
bool Tietokanta::rajapintafunktioTietokanta()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("salaisuus");
    db.setDatabaseName("salaisuus");
    db.setUserName("salaisuus");
    db.setPassword("salaisuus");
    if (!db.open()) {
        qDebug() << "Unable to establish a database connection";
        return false;
    }
    else {
        model = new QSqlTableModel;
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
        model->setTable("tapahtuma");
        model->select();
        int row = model->rowCount();
        model->insertRows(row,1);
        model->setData(model->index(row, 1), tilinumero);
        model->setData(model->index(row, 3), "NOSTO");
        model->setData(model->index(row, 4), maara);
        model->submitAll();
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
        salasana = pinkysy.value(0).toInt();
    }

    //int ch = QString::compare(annettupin,salasana);
    if(annettupin == salasana){
        pinOk = true;
    }
    if (annettupin != salasana) {
        pinOk = false;
    }
    return pinOk;
}

void Tietokanta::tarkastaTapahtumat()
{
    QSqlRecord record;
    QDate aika;
    QString paiva, tapahtuma, maara;
    QString status = QString("tilinumero = '%1' order by aika DESC limit 10").arg(tilinumero);
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
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PVM"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Tapahtuma"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Määrä"));
    TietokantaDialog *dialog = new TietokantaDialog;
    dialog->luoTable(*model);
}



