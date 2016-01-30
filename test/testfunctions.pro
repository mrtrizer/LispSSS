QT       += core testlib
QT       -= gui

TARGET = ssse
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -lffi

include("../src/lispsss.pri")

QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp testfunctions.cpp
HEADERS += testfunctions.h

target.path = /usr/local/bin
INSTALLS += target
