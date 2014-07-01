#include "func_prog.h"
#include "lispexecuter.h"
#include "atomnildata.h"

Result Func_prog::run_(const Arguments & arguments, Memory *stack) const
{
    Memory localStack (stack);
    Arguments::const_iterator i;
    Result result;
    for (i = arguments.begin(); i != arguments.end(); i++)
        result = executer->functionHandler(i->getData(),&localStack);
    return result;
}
