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
INCLUDEPATH = ./functions

QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp \
    lispstring.cpp \
    message.cpp \
    lispexecuter.cpp \
    heap.cpp \
    stack.cpp \
    var.cpp \
    lispnode.cpp \
    funccontroller.cpp \
    function.cpp \
    functions/func_defun.cpp \
    functions/func___global.cpp \
    value.cpp \
    functions/func__plus_.cpp

HEADERS += \
    lispstring.h \
    config.h \
    message.h \
    lispexecuter.h \
    heap.h \
    stack.h \
    var.h \
    lispnode.h \
    funccontroller.h \
    function.h \
    functions/func_defun.h \
    functions/func___global.h \
    value.h \
    functions/func__plus_.h

OTHER_FILES += \
    README \
    calc_ssslisp.lsp \
    test.sss
