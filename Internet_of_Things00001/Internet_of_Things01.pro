#-------------------------------------------------
#
# Project created by QtCreator 2022-10-17T08:21:53
#
#-------------------------------------------------

QT       += core gui charts multimedia multimediawidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Internet_of_Things01
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    newwindow.cpp \
    user.cpp \
    erwei.cpp \
    action.cpp \
    root_win.cpp \
    root_set.cpp \
    findpwd.cpp \
    lineseries.cpp \
    saoma.cpp \
    run_contorl.cpp

HEADERS += \
        widget.h \
    newwindow.h \
    user.h \
    erwei.h \
    action.h \
    root_win.h \
    root_set.h \
    findpwd.h \
    lineseries.h \
    saoma.h \
    run_contorl.h

FORMS += \
        widget.ui \
    newwindow.ui \
    erwei.ui \
    action.ui \
    root_win.ui \
    root_set.ui \
    findpwd.ui \
    lineseries.ui \
    saoma.ui \
    run_contorl.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
