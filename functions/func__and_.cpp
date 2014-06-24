#include "func__and_.h"
#include "atomtdata.h"
#include "atomnildata.h"

Func__And_::Func__And_():Function(SUBR,2)
{
}

Result Func__And_::run_(const Arguments & arguments, Memory *stack) const
{
    (void)stack;
    AtomNilData nil;
    if ((!arguments[0].getData()->isEqual(&nil)) && (!arguments[1].getData()->isEqual(&nil)))
        return Result(new AtomTData());
    else
        return Result(new AtomNilData());
}
