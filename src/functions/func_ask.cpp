#include "func_ask.h"
#include "atomstrdata.h"
#include "atomfloatdata.h"
#include "atomintdata.h"

Result Func_ask::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;
    Arguments::const_iterator i;
    if (out)
        for (i = arguments.begin(); i != arguments.end(); i++)
            if (i->getData()->getDataType() == Data::ATOM_STR)
                *out << ((AtomStrData *)i->getData())->getString();
            else
                *out << i->getData()->toString();
    char buff[1000];
    in->getline(buff,1000);
    std::string str(buff);
    *out << std::endl;
    if (((str[0] >= '0') && (str[0] <= '9')) ||
            ((str[0] == '-') && (str[1] >= '0') && (str[1] <= '9')))
    {
        int pointCount = 0;
        for (unsigned int i = 0; i < str.size(); i++)
            if ((str[i] == '.') or (str[i] == ','))
                pointCount++;
        if (pointCount > 1)
             return Result(new AtomStrData(str));
        if (pointCount == 1)
            return Result(new AtomFloatData(atof(str.c_str())));
        else
            return Result(new AtomIntData(atoi(str.c_str())));
    }
    return Result(new AtomStrData(str));
}
