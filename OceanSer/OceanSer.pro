#-------------------------------------------------
#
# Project created by QtCreator 2014-08-25T11:26:17
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OceanSer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    statisticdialog.cpp \
    quesmdialog.cpp \
    cylindermap.cpp

HEADERS  += widget.h \
    statisticdialog.h \
    quesmdialog.h \
    cylindermap.h

FORMS    += widget.ui \
    statisticdialog.ui \
    quesmdialog.ui
