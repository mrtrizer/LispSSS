#include "func_cdr.h"
#include "atomnildata.h"
#include "listdata.h"

Func_cdr::Func_cdr():Function(SUBR,1)
{
}

Result Func_cdr::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;
    if (arguments[0].getData()->getDataType() == Data::LIST)
    {
        ListData * list = (ListData *)arguments[0].getData();
        if (list->list.size() > 1)
        {
            ListData * result = new ListData ();
            for (std::vector<LispNode>::iterator i = list->list.begin() + 1; i != list->list.end(); i++)
                result->list.push_back(*i);
            return Result(result);
        }
        else
            return Result(new AtomNilData());
    }
    else
        ERROR_MESSAGE("Function cdr. Argument must be LIST.");
    return Result(new AtomNilData());
}
