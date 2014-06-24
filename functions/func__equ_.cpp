#include "func__equ_.h"
#include "atomtdata.h"
#include "atomnildata.h"

Func__Equ_::Func__Equ_():Function("==",SUBR,-1,2)
{
}

Result Func__Equ_::run_(const Arguments & arguments) const
{
    bool result = true;
    Arguments::const_iterator i;
    for (i = arguments.begin(); i != arguments.end() - 1; i++)
        if (!i->getData()->isEqual((i + 1)->getData()))
        {
            result = false;
            break;
        }
    if (result)
        return Result(new AtomTData());
    else
        return Result(new AtomNilData());
}
