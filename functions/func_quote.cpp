#include "func_quote.h"
#include "atomnildata.h"

Func_quote::Func_quote():Function("quote",FSUBR,1)
{
}

Result Func_quote::run_(const Arguments &arguments) const
{
    if (arguments[0].getData()->getDataType() == Data::LIST)
        //return Result(new ListData(new LispNode((Data *)arguments[0].getData()->getClone())));
        return Result(arguments[0].getData()->getClone());
    else
        ERROR_MESSAGE("Argument must be LIST.");
    return Result(new AtomNilData());
}
