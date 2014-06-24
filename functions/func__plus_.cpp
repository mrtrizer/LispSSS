#include "func__plus_.h"
#include "atomfloatdata.h"
#include "atomintdata.h"

Func__Plus_::Func__Plus_():Function(SUBR,-1,2)
{
}

Result Func__Plus_::run_(const Arguments & arguments, Memory *stack) const
{
    (void)stack;
    Arguments::const_iterator i;
    float sum;
    for (i = arguments.begin(); i != arguments.end(); i++)
    {
        const Data * data = i->getData();
        if (data->getDataType() == Data::ATOM_FLOAT)
            sum += ((AtomFloatData *)data)->getNum();
        else
        {
            if (data->getDataType() == Data::ATOM_INT)
                sum += ((AtomIntData *)data)->getNum();
            else
                ERROR_MESSAGE("You can use only INT and FLOAT variables with + function");
        }
    }
    return Result(new AtomFloatData(sum));
}
