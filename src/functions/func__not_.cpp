#include "func__not_.h"
#include "atomtdata.h"
#include "atomnildata.h"

Func__Not_::Func__Not_():Function(SUBR,1)
{
}

Result Func__Not_::run_(const Arguments & arguments, Memory *stack) const
{
    (void)stack;
    AtomNilData nil;
    if (arguments[0].getData()->isEqual(&nil))
        return Result(new AtomTData());
    else
        return Result(new AtomNilData());
}
