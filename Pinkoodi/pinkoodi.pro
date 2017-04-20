#-------------------------------------------------
#
# Project created by QtCreator 2017-04-12T09:10:42
#
#-------------------------------------------------

QT += widgets gui
TARGET = pinkoodi
TEMPLATE = lib

DEFINES += PINKOODI_LIBRARY

SOURCES += pinkoodi.cpp \
    pinkoodimoottoridialogi.cpp

HEADERS += pinkoodi.h\
        pinkoodi_global.h \
    pinkoodimoottoridialogi.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    pinkoodimoottoridialogi.ui

DESTDIR = C:\Users\OMISTAJ\Desktop\Kurssimateriaali\2017K\Ohjelmoinnin_sovellusprojekti\build-BankSimul-Desktop_Qt_5_7_0_MinGW_32bit-Release\release
