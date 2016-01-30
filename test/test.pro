QT += core testlib
QT -= gui

TARGET = test
CONFIG += console
CONFIG -= app_bundle
CONFIG += testcase

TEMPLATE = app

LIBS += -lffi

include("../src/lispsss.pri")

QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp testfunctions.cpp
HEADERS += testfunctions.h

