#include "func__notequ_.h"
#include "atomtdata.h"
#include "atomnildata.h"

Result Func__NotEqu_::run_(const Arguments & arguments, Memory *stack) const
{
    (void) stack;
    bool result = true;
    Arguments::const_iterator i;
    for (i = arguments.begin(); i != arguments.end() - 1; i++)
        if (!i->getData()->isEqual((i + 1)->getData()))
        {
            result = false;
            break;
        }
    if (!result)
        return Result(new AtomTData());
    else
        return Result(new AtomNilData());
}
