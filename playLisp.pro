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
    functions/func__plus_.cpp \
    functions/func__minus_.cpp \
    functions/func__mul_.cpp \
    functions/func__div_.cpp \
    functions/func_print.cpp \
    functions/func_if.cpp \
    functions/func__equ_.cpp \
    functions/func_while.cpp \
    functions/func_return.cpp \
    functions/func_prog.cpp \
    functions/func_setq.cpp \
    functions/func__notequ_.cpp \
    lispfunction.cpp \
    functions/func_ask.cpp

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
    functions/func__plus_.h \
    functions/func__minus_.h \
    functions/func__mul_.h \
    functions/func__div_.h \
    functions/func_print.h \
    functions/func_if.h \
    functions/func__equ_.h \
    functions/func_while.h \
    functions/func_return.h \
    functions/func_prog.h \
    functions/func_setq.h \
    functions/func__notequ_.h \
    lispfunction.h \
    functions/func_ask.h

OTHER_FILES += \
    README \
    calc_ssslisp.lsp \
    test.sss
