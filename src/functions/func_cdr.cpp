#include "func_cdr.h"
#include "atomnildata.h"
#include "listdata.h"

Result Func_cdr::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;
    TEST_ARG(0,Data::LIST);
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
    return Result(new AtomNilData());
}
