#include "func_prog.h"
#include "stack.h"
#include "lispexecuter.h"

Func_prog::Func_prog(LispExecuter *executer):Function("prog",FSUBR),executer(executer)
{
}

Result Func_prog::run_(const Arguments & arguments) const
{

    Arguments::const_iterator i;
    Result result;
    for (i = arguments.begin(); i != arguments.end(); i++)
        result = executer->functionHandler(i->getData());
    return result;
}
