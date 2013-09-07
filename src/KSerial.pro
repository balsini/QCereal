#-------------------------------------------------
#
# Project created by QtCreator 2013-09-06T17:24:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KSerial
TEMPLATE = app

LIBS     += \
    -lkdeui

SOURCES  += \
    main.cpp \
    mainwindow.cpp \
    aboutwindow.cpp

HEADERS  += \
    mainwindow.h \
    aboutwindow.h

FORMS    += \
    mainwindow.ui \
    aboutwindow.ui

RESOURCES += \
    resources.qrc
