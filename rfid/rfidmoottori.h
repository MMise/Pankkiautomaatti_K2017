#ifndef RFIDMOOTTORI_H
#define RFIDMOOTTORI_H
#include <QString>
#include <QSerialPort>
#include <QDebug>
#include <QtCore>
#include <QObject>
#include <QTimer>

class rfidMoottori : public QObject
{
    Q_OBJECT

public:
    rfidMoottori();
    ~rfidMoottori();
    void ConnectSerial();
signals:
    void LueMuisti(QString arg);
private:
    QString muisti;
    QSerialPort *serial;
    QTimer *timer;
private slots:
    void serialReceived();
    void update();
    void disconnected(QSerialPort::SerialPortError e);
};

#endif // RFIDMOOTTORI_H
