#include "func_prog.h"
#include "lispexecuter.h"

Func_prog::Func_prog(LispExecuter *executer):Function(FSUBR),executer(executer)
{
}

Result Func_prog::run_(const Arguments & arguments, Memory *stack) const
{
    Memory localStack (stack);
    Arguments::const_iterator i;
    Result result;
    for (i = arguments.begin(); i != arguments.end(); i++)
        result = executer->functionHandler(i->getData(),&localStack);
    return result;
}
