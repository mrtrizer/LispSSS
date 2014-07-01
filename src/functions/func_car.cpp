#include "func_car.h"
#include "listdata.h"
#include "atomnildata.h"

Func_car::Func_car():Function(SUBR,1)
{
}

Result Func_car::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;
    if (arguments[0].getData()->getDataType() == Data::LIST)
        return Result(((ListData *)arguments[0].getData())->list[0].data->getClone());
    else
        ERROR_MESSAGE("Function car. Argument must be LIST.");
    return Result(new AtomNilData());
}
