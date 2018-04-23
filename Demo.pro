#-------------------------------------------------
#
# Project created by QtCreator 2017-12-05T17:10:51
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindows.cpp \
    rack.cpp \
    device.cpp \
    vm.cpp \
    udpcontroller.cpp

HEADERS  += mainwindows.h \
    rack.h \
    device.h \
    vm.h \
    udpcontroller.h

FORMS    += mainwindows.ui \
    rack.ui \
    device.ui \
    vm.ui
