#include "func__or_.h"
#include "atomtdata.h"
#include "atomnildata.h"

Result Func__Or_::run_(const Arguments & arguments, Memory *stack) const
{
    (void)stack;
    AtomNilData nil;
    if ((!arguments[0].getData()->isEqual(&nil)) || (!arguments[1].getData()->isEqual(&nil)))
        return Result(new AtomTData());
    else
        return Result(new AtomNilData());
}
