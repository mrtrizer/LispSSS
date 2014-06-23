#include "func_ask.h"

Func_ask::Func_ask(std::ostream *out, std::istream *in):Function("ask",SUBR,-1),in(in),out(out)
{
}

Result Func_ask::run_(const Arguments &arguments)
{
    Arguments::const_iterator i;
    if (out)
        for (i = arguments.begin(); i != arguments.end(); i++)
            if (i->getData()->getDataType() == Data::ATOM_STR)
                *out << ((AtomStrData *)i->getData())->getString() << ' ';
            else
                *out << i->getData()->toString() << ' ';
    *out << std::endl;
    std::string str;
    *in >> str;
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
