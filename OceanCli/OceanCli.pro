#-------------------------------------------------
#
# Project created by QtCreator 2014-08-19T14:37:00
#
#-------------------------------------------------

QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OceanCli
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    logowidget.cpp \
    datewidget.cpp \
    weatherwidget.cpp \
    showwidget.cpp \
    questionwidget.cpp \
    infowidget.cpp \
    videowidget.cpp \
    questiondialog.cpp

HEADERS  += widget.h \
    logowidget.h \
    datewidget.h \
    weatherwidget.h \
    showwidget.h \
    questionwidget.h \
    infowidget.h \
    videowidget.h \
    questiondialog.h

FORMS    += widget.ui \
    logowidget.ui \
    datewidget.ui \
    weatherwidget.ui \
    showwidget.ui \
    questionwidget.ui \
    infowidget.ui \
    videowidget.ui \
    questiondialog.ui

RESOURCES += \
    Ocean.qrc

OTHER_FILES += \
    images/4043.jpg
