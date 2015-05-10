#-------------------------------------------------
#
# Project created by QtCreator 2013-07-11T14:29:52
#
#-------------------------------------------------

INCLUDEPATH += $$PWD/functions $$PWD/data_types $$PWD/
unix:INCLUDEPATH += /usr/local/lib/libffi-3.99999/include

unix:LIBS += -L/usr/local/lib -lffi

QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += \
    $$PWD/lispstring.cpp \
    $$PWD/message.cpp \
    $$PWD/lispexecuter.cpp \
    $$PWD/heap.cpp \
    $$PWD/var.cpp \
    $$PWD/lispnode.cpp \
    $$PWD/function.cpp \
    $$PWD/functions/func_defun.cpp \
    $$PWD/value.cpp \
    $$PWD/functions/func__plus_.cpp \
    $$PWD/functions/func__minus_.cpp \
    $$PWD/functions/func__mul_.cpp \
    $$PWD/functions/func__div_.cpp \
    $$PWD/functions/func_print.cpp \
    $$PWD/functions/func_if.cpp \
    $$PWD/functions/func__equ_.cpp \
    $$PWD/functions/func_while.cpp \
    $$PWD/functions/func_return.cpp \
    $$PWD/functions/func_prog.cpp \
    $$PWD/functions/func_setq.cpp \
    $$PWD/functions/func__notequ_.cpp \
    $$PWD/lispfunction.cpp \
    $$PWD/functions/func_ask.cpp \
    $$PWD/functions/func_quote.cpp \
    $$PWD/functions/func_car.cpp \
    $$PWD/functions/func_cdr.cpp \
    $$PWD/functions/func_func.cpp \
    $$PWD/memory.cpp \
    $$PWD/data.cpp \
    $$PWD/data_types/listdata.cpp \
    $$PWD/data_types/atomdata.cpp \
    $$PWD/data_types/funcdata.cpp \
    $$PWD/data_types/atomintdata.cpp \
    $$PWD/data_types/atomfloatdata.cpp \
    $$PWD/data_types/atomstrdata.cpp \
    $$PWD/data_types/atomtdata.cpp \
    $$PWD/data_types/atomnildata.cpp \
    $$PWD/functions/func__greater_.cpp \
    $$PWD/functions/func__less_.cpp \
    $$PWD/functions/func__greaterequ_.cpp \
    $$PWD/functions/func__lessequ_.cpp \
    $$PWD/functions/func__and_.cpp \
    $$PWD/functions/func__or_.cpp \
    $$PWD/functions/func__not_.cpp \
    $$PWD/functions/func__power_.cpp \
    $$PWD/functions/func_continue.cpp \
    $$PWD/functions/func_exec.cpp \
    $$PWD/externfunction.cpp \
    $$PWD/functions/func_parse.cpp \
    $$PWD/pos.cpp \
    $$PWD/functions/func_size.cpp \
    $$PWD/lexicalanalyzer.cpp \
    $$PWD/lexem.cpp

HEADERS += \
    $$PWD/lispstring.h \
    $$PWD/config.h \
    $$PWD/message.h \
    $$PWD/lispexecuter.h \
    $$PWD/heap.h \
    $$PWD/var.h \
    $$PWD/lispnode.h \
    $$PWD/function.h \
    $$PWD/functions/func_defun.h \
    $$PWD/value.h \
    $$PWD/functions/func__plus_.h \
    $$PWD/functions/func__minus_.h \
    $$PWD/functions/func__mul_.h \
    $$PWD/functions/func__div_.h \
    $$PWD/functions/func_print.h \
    $$PWD/functions/func_if.h \
    $$PWD/functions/func__equ_.h \
    $$PWD/functions/func_while.h \
    $$PWD/functions/func_return.h \
    $$PWD/functions/func_prog.h \
    $$PWD/functions/func_setq.h \
    $$PWD/functions/func__notequ_.h \
    $$PWD/lispfunction.h \
    $$PWD/functions/func_ask.h \
    $$PWD/functions/func_quote.h \
    $$PWD/functions/func_car.h \
    $$PWD/functions/func_cdr.h \
    $$PWD/functions/func_func.h \
    $$PWD/memory.h \
    $$PWD/data.h \
    $$PWD/data_types/listdata.h \
    $$PWD/data_types/atomdata.h \
    $$PWD/data_types/funcdata.h \
    $$PWD/data_types/atomintdata.h \
    $$PWD/data_types/atomfloatdata.h \
    $$PWD/data_types/atomstrdata.h \
    $$PWD/data_types/atomtdata.h \
    $$PWD/data_types/atomnildata.h \
    $$PWD/functions/func__greater_.h \
    $$PWD/functions/func__less_.h \
    $$PWD/functions/func__greaterequ_.h \
    $$PWD/functions/func__lessequ_.h \
    $$PWD/functions/func__and_.h \
    $$PWD/functions/func__or_.h \
    $$PWD/functions/func__not_.h \
    $$PWD/functions/func__power_.h \
    $$PWD/functions/func_continue.h \
    $$PWD/functions/func_exec.h \
    $$PWD/externfunction.h \
    $$PWD/functions/func_parse.h \
    $$PWD/pos.h \
    $$PWD/functions/func_size.h \
    $$PWD/lexicalanalyzer.h \
    $$PWD/lexem.h

OTHER_FILES += \
    $$PWD/README
