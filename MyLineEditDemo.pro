#-------------------------------------------------
#
# Project created by QtCreator 2014-05-26T09:13:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyLineEditDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    searchedit.cpp \
    clearlabel.cpp \
    mylineedit.cpp

HEADERS  += mainwindow.h \
    searchedit.h \
    clearlabel.h \
    mylineedit.h

FORMS    += mainwindow.ui

RESOURCES += \
    MyResource.qrc
