#-------------------------------------------------
#
# Project created by QtCreator 2017-04-11T12:06:49
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BankSimul
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:LIBS += "C:\Users\OMISTAJ\Desktop\Kurssimateriaali\2017K\Ohjelmoinnin_sovellusprojekti\build-BankSimul-Desktop_Qt_5_7_0_MinGW_32bit-Release\release\pinkoodi.dll"
win32:LIBS += "C:\Users\OMISTAJ\Desktop\Kurssimateriaali\2017K\Ohjelmoinnin_sovellusprojekti\build-BankSimul-Desktop_Qt_5_7_0_MinGW_32bit-Release\release\tietokanta.dll"
win32:LIBS += "C:\Users\OMISTAJ\Desktop\Kurssimateriaali\2017K\Ohjelmoinnin_sovellusprojekti\build-BankSimul-Desktop_Qt_5_7_0_MinGW_32bit-Release\release\rfid.dll"
