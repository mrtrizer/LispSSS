#include "func_return.h"
#include "func_while.h"

Func_return::Func_return():Function("return",SUBR,1)
{
}

Result Func_return::run_(const Arguments & arguments)
{
    throw Func_while::return_exception((Result)arguments[0]);
    return Result(new AtomNilData());
}
