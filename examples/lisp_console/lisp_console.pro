#-------------------------------------------------
#
# Project created by QtCreator 2013-07-11T14:29:52
#
#-------------------------------------------------

#QT       += core

QT       -= gui

TARGET = sssc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

include("../../src/lispsss.pri")

LIBS += -L../libs/ -lffi
#LIBS += -lffi

QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp
HEADERS += 

