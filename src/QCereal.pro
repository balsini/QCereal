#-------------------------------------------------
#
# Project created by QtCreator 2015-09-22T16:53:10
#
#-------------------------------------------------

QT       += core gui widgets serialport

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = QCereal
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    serialsetup.cpp \
    console.cpp

HEADERS  += mainwindow.h \
    serialsetup.h \
    console.h

FORMS    += mainwindow.ui \
    serialsetup.ui
