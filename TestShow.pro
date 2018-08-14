#-------------------------------------------------
#
# Project created by QtCreator 2018-08-13T15:45:28
#
#-------------------------------------------------

QT       += core gui network sql
QT       += datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestShow
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    surfacegraph.cpp \
    unit/lasterdata.cpp \
    unit/lasterdevunit.cpp \
    unit/net/devchannel.cpp \
    unit/protocol/devprotocol.cpp \
    unit/config/trafficsettings.cpp \
    unit/mathhelper.cpp \
    unit/virtualbackground.cpp \
    unit/SICKProc.cpp \
    unit/com/posix_qextserialport.cpp \
    unit/com/qextserialbase.cpp \
    unit/com/qextserialport.cpp \
    unit/com/win_qextserialport.cpp \
    unit/alg/trafficalg.cpp \
    unit/vehicleinfo.cpp \
    unit/db/datarecord.cpp \
    unit/DBDefines.cpp

HEADERS += \
        mainwindow.h \
    surfacegraph.h \
    unit/lasterdata.h \
    unit/lasterdevunit.h \
    unit/net/devchannel.h \
    unit/protocol/devprotocol.h \
    unit/config/trafficsettings.h \
    unit/mathhelper.h \
    unit/virtualbackground.h \
    unit/SICKProc.h \
    unit/com/posix_qextserialport.h \
    unit/com/qextserialbase.h \
    unit/com/qextserialport.h \
    unit/com/win_qextserialport.h \
    unit/alg/trafficalg.h \
    unit/vehicleinfo.h \
    unit/db/datarecord.h \
    unit/DBDefines.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += ./unit \
               ./unit/config
