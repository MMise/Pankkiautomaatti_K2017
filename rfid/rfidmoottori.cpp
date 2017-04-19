#include "rfidmoottori.h"
#include <QSerialPortInfo>

rfidMoottori::rfidMoottori()
{
    serial = new QSerialPort();
    timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    ConnectSerial();
}

rfidMoottori::~rfidMoottori() {
    serial->close();
}

void rfidMoottori::ConnectSerial() {
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) { //etsi laite
           if(info.serialNumber() == "OL415CE004C536F") {
               serial->setPort(info);
               break;
           }
    }

    //serial->setPortName("COM12"); //saattaa vaihtua
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::HardwareControl);
    if (serial->open(QIODevice::ReadWrite))
    {
        qDebug() << "Portti avattu: " << serial->portName();
        serial->readAll(); //tyhjennä laitteen muisti
        connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
        connect(serial, SIGNAL(errorOccurred(enum QSerialPort::SerialPortError)), this, SLOT(disconnected(QSerialPort::SerialPortError)));
    }
    else {
        //qDebug() << "muodostetaan yhteyttä...";
        timer->start(1000);
    }
}

void rfidMoottori::update() {
    ConnectSerial();
}

void rfidMoottori::disconnected(QSerialPort::SerialPortError e) {
    if(e == QSerialPort::ResourceError) {
        qDebug() << "Yhteys laitteeseen katkesi, muodostetaan yhteyttä..";
        disconnect(serial, 0, 0, 0);
        serial->close();
        timer->start(1000);
    } else qDebug() << "Odottamaton virhe";
}

void rfidMoottori::serialReceived() {
    muisti = serial->readAll();
    muisti = muisti.remove(QRegExp("[^\\d\\w]")); //Siivoa laitteen palauttama ASCII-sotku
    qDebug() << "Lukulaite: " << muisti;
    emit LueMuisti(muisti);
}
