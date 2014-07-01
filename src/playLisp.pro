#-------------------------------------------------
#
# Project created by QtCreator 2013-07-11T14:29:52
#
#-------------------------------------------------

#QT       += core

QT       -= gui

TARGET = playLisp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
INCLUDEPATH = ./functions ./data_types ../libs

LIBS += -L../libs/ -lffi
#LIBS += -lffi

QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp \
    lispstring.cpp \
    message.cpp \
    lispexecuter.cpp \
    heap.cpp \
    var.cpp \
    lispnode.cpp \
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
    functions/func_ask.cpp \
    functions/func_quote.cpp \
    functions/func_car.cpp \
    functions/func_cdr.cpp \
    functions/func_func.cpp \
    memory.cpp \
    data.cpp \
    data_types/listdata.cpp \
    data_types/atomdata.cpp \
    data_types/funcdata.cpp \
    data_types/atomintdata.cpp \
    data_types/atomfloatdata.cpp \
    data_types/atomstrdata.cpp \
    data_types/atomtdata.cpp \
    data_types/atomnildata.cpp \
    functions/func__greater_.cpp \
    functions/func__less_.cpp \
    functions/func__greaterequ_.cpp \
    functions/func__lessequ_.cpp \
    functions/func__and_.cpp \
    functions/func__or_.cpp \
    functions/func__not_.cpp \
    functions/func__power_.cpp \
    functions/func_continue.cpp \
    functions/func_exec.cpp \
    externfunction.cpp \
    functions/func_parse.cpp \
    pos.cpp \
    functions/func_size.cpp

HEADERS += \
    lispstring.h \
    config.h \
    message.h \
    lispexecuter.h \
    heap.h \
    var.h \
    lispnode.h \
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
    functions/func_ask.h \
    functions/func_quote.h \
    functions/func_car.h \
    functions/func_cdr.h \
    functions/func_func.h \
    memory.h \
    data.h \
    data_types/listdata.h \
    data_types/atomdata.h \
    data_types/funcdata.h \
    data_types/atomintdata.h \
    data_types/atomfloatdata.h \
    data_types/atomstrdata.h \
    data_types/atomtdata.h \
    data_types/atomnildata.h \
    functions/func__greater_.h \
    functions/func__less_.h \
    functions/func__greaterequ_.h \
    functions/func__lessequ_.h \
    functions/func__and_.h \
    functions/func__or_.h \
    functions/func__not_.h \
    functions/func__power_.h \
    functions/func_continue.h \
    functions/func_exec.h \
    externfunction.h \
    functions/func_parse.h \
    pos.h \
    functions/func_size.h

OTHER_FILES += \
    README \
    calc_ssslisp.lsp \
    test.sss \
    test_simple.sss \
    sort.sss \
    func_test.sss \
    operator_tests.sss \
    parse_test.sss
