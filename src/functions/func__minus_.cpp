#include "func__minus_.h"
#include "atomfloatdata.h"
#include "atomintdata.h"

Result Func__Minus_::run_(const Arguments & arguments, Memory *stack) const
{
    (void) stack;
    Arguments::const_iterator i;
    double sum;
    for (i = arguments.begin(); i != arguments.end(); i++)
    {
        const Data * data = i->getData();
        if (data->getDataType() == Data::ATOM_FLOAT)
        {
            if (i == arguments.begin())
                sum = ((AtomFloatData *)data)->getNum();
            else
                sum -= ((AtomFloatData *)data)->getNum();
        }
        else
        {
            if (data->getDataType() == Data::ATOM_INT)
            {
                if (i == arguments.begin())
                    sum = ((AtomIntData *)data)->getNum();
                else
                    sum -= ((AtomIntData *)data)->getNum();
            }
            else
                ERROR_MESSAGE("You can use only INT and double variables with this function");
        }
    }
    return Result(new AtomFloatData(sum));
}
