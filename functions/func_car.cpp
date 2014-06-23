#include "func_car.h"

Func_car::Func_car():Function("car",SUBR,1)
{
}

Result Func_car::run_(const Arguments &arguments)
{
    if (arguments[0].getData()->getDataType() == Data::LIST)
        return Result(((ListData *)arguments[0].getData())->getRoot()->data->getClone());
    else
        ERROR_MESSAGE("Argument must be LIST.");
    return Result(new AtomNilData());
}
