#include "func_parse.h"
#include "lispstring.h"
#include "atomstrdata.h"

Result Func_parse::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;
    std::string str;
    TEST_ARG(0,Data::ATOM_STR);
    str = ((AtomStrData *)arguments[0].getData())->getString();
    LispString lispStr (str.c_str());
    return Result(lispStr.getRoot()->data->getClone());
}
