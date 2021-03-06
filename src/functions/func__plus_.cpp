#include "func__plus_.h"
#include "atomfloatdata.h"
#include "atomintdata.h"

Result Func__Plus_::run_(const Arguments & arguments, Memory *stack) const
{
    (void)stack;
    Arguments::const_iterator i;
    double sum;
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
                ERROR_MESSAGE("You can use only INT and double variables with + function");
        }
    }
    return Result(new AtomFloatData(sum));
}
