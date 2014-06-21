#-------------------------------------------------
#
# Project created by QtCreator 2013-07-11T14:29:52
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = playLisp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp \
    lispstring.cpp \
    message.cpp \
    lispexecuter.cpp \
    heap.cpp \
    stack.cpp \
    var.cpp \
    lispnode.cpp

HEADERS += \
    lispstring.h \
    config.h \
    message.h \
    lispexecuter.h \
    heap.h \
    stack.h \
    var.h \
    lispnode.h

OTHER_FILES += \
    README \
    calc_ssslisp.lsp
