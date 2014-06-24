#include "func_cdr.h"
#include "atomnildata.h"
#include "listdata.h"

Func_cdr::Func_cdr():Function("cdr",SUBR,1)
{
}

Result Func_cdr::run_(const Arguments &arguments) const
{
    if (arguments[0].getData()->getDataType() == Data::LIST)
    {
        ListData * list = (ListData *)arguments[0].getData();
        if (list->getRoot()->next != 0)
            return Result(new ListData (new LispNode(*list->getRoot()->next)));
        else
            return Result(new AtomNilData());
    }
    else
        ERROR_MESSAGE("Argument must be LIST.");
    return Result(new AtomNilData());
}
