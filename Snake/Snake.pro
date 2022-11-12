#-------------------------------------------------
#
# Project created by QtCreator 2016-09-02T10:48:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += debug_and_release
CONFIG(debug, debug|release){
    TARGET = ../../_debug/Snake
} else {
    TARGET = ../../_release/Snake
}
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GameArea.cpp

HEADERS  += mainwindow.h \
    GameArea.h

FORMS    += mainwindow.ui

RESOURCES += \
    rc.qrc

RC_FILE = app.rc
