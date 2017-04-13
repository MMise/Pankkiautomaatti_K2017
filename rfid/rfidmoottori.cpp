#include "rfidmoottori.h"

rfidMoottori::rfidMoottori()
{
    serial = new QSerialPort();
    serial->setPortName("COM12"); //saattaa vaihtua
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::HardwareControl);
    if (serial->open(QIODevice::ReadWrite))
    {
        qDebug() << "Portti avattu: " << serial->portName();
    }
    else
    {
        qDebug() << "VIRHE: Portin avaaminen ei onnistunut!";
    }
    serial->readAll(); //tyhjennä laitteen muisti
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));
}

rfidMoottori::~rfidMoottori() {
    serial->close();
}

void rfidMoottori::serialReceived() {
    muisti = serial->readAll();
    muisti = muisti.remove(QRegExp("[^\\d\\w]")); //Siivoa laitteen palauttama ASCII-sotku
    qDebug() << "Lukulaite: " << muisti;
    emit LueMuisti(muisti);
}
