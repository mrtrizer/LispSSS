#include "func___global.h"

Func___global::Func___global():Function("__global",FSUBR)
{
}

Result Func___global::run_(const Arguments & arguments)
{
    (void) arguments;
    return Result(new AtomNilData());
}