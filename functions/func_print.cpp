#include "func_print.h"

Func_print::Func_print(std::ostream *out):Function("print",SUBR,-1,1),out(out)
{

}

Result Func_print::run_(const Arguments &arguments)
{
    Arguments::const_iterator i;
    if (out)
        for (i = arguments.begin(); i != arguments.end(); i++)
            *out << i->getData()->toString() << std::endl;
    return Result(new AtomNilData());
}
