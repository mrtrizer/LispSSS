#include "func_car.h"
#include "listdata.h"
#include "atomnildata.h"

Result Func_car::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;
    TEST_ARG(0,Data::LIST);
    return Result(((ListData *)arguments[0].getData())->list[0].data->getClone());
}
