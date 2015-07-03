#-------------------------------------------------
#
# Project created by QtCreator 2015-06-06T14:07:13
#
#-------------------------------------------------

CONFIG += c++11
QT       += core gui

RC_FILE += image.rc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BankImitate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    customertype.cpp \
    servertype.cpp \
    titlewin.cpp \
    queueimitation.cpp \
    brokenimage.cpp \
    controlwin.cpp

HEADERS  += mainwindow.h \
    customertype.h \
    servertype.h \
    myqueue.h \
    qtheader.h \
    titlewin.h \
    queueimitation.h \
    brokenimage.h \
    controlwin.h
