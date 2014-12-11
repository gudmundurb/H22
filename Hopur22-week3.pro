#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T15:41:26
#
#-------------------------------------------------

QT       += core gui
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hopur22-week3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    computerrepository.cpp \
    linkrepository.cpp \
    link.cpp \
    scientist.cpp \
    scientistrepository.cpp \
    services.cpp \
    utilities.cpp

HEADERS  += mainwindow.h \
    computer.h \
    computerrepository.h \
    linkrepository.h \
    link.h \
    scientist.h \
    scientistrepository.h \
    services.h \
    utilities.h

FORMS    += mainwindow.ui
