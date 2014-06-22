#include "func__plus_.h"

Func__plus_::Func__plus_():Function("+",SUBR,-1,2)
{
}

Result Func__plus_::run_(const Arguments & arguments)
{
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
                ERROR_MESSAGE("You can use only INT and FLOAT variables with this function");
        }
    }
    return Result(new AtomFloatData(sum));
}