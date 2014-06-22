#include "func_prog.h"

Func_prog::Func_prog():Function("prog",SUBR)
{
}

Result Func_prog::run_(const Arguments & arguments)
{
    (void) arguments;
    return Result(new AtomNilData());
}
