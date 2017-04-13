#ifndef RFIDMOOTTORI_H
#define RFIDMOOTTORI_H
#include <QString>
#include <QSerialPort>
#include <QDebug>
#include <QtCore>
#include <QObject>


class rfidMoottori : public QObject
{
    Q_OBJECT

public:
    rfidMoottori();
    ~rfidMoottori();
signals:
    void LueMuisti(QString arg);
private:
    QString muisti;
    QSerialPort *serial;
private slots:
    void serialReceived();
};

#endif // RFIDMOOTTORI_H
