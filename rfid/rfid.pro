#-------------------------------------------------
#
# Project created by QtCreator 2017-04-13T11:08:49
#
#-------------------------------------------------

QT       -= gui
QT += core serialport

TARGET = rfid
TEMPLATE = lib

DEFINES += RFID_LIBRARY

SOURCES += rfid.cpp \
    rfidmoottori.cpp

HEADERS += rfid.h\
        rfid_global.h \
    rfidmoottori.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
