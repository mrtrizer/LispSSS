#include "func_size.h"
#include "atomintdata.h"
#include "listdata.h"

Result Func_size::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;
    TEST_ARG(0,Data::LIST)
    return Result(new AtomIntData((int)((ListData*)arguments[0].getData())->list.size()));
}
