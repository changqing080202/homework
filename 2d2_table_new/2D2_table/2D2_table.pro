QT += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

SOURCES += \
    main.cpp \
    widgettable.cpp \
    patientmodel.cpp \
    tcpserver.cpp \
    widgetdraw.cpp

HEADERS += \
    widgettable.h \
    patientmodel.h \
    tcpserver.h \
    widgetdraw.h \
    bufdata.h
