#include "func_return.h"
#include "func_while.h"
#include "atomnildata.h"

Result Func_return::run_(const Arguments & arguments, Memory *stack) const
{
    (void) stack;
    throw Func_while::return_exception((Result)arguments[0]);
    return Result(new AtomNilData());
}
