#include "func_print.h"
#include "atomstrdata.h"
#include "atomnildata.h"

Func_print::Func_print(std::ostream *out):Function(SUBR,-1,1),out(out)
{

}

Result Func_print::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;
    Arguments::const_iterator i;
    if (out)
    {
        for (i = arguments.begin(); i != arguments.end(); i++)
            if (i->getData()->getDataType() == Data::ATOM_STR)
                *out << ((AtomStrData *)i->getData())->getString();
            else
                *out << i->getData()->toString();
        *out << std::endl;
    }
    return Result(new AtomNilData());
}
