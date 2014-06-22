#include "func_prog.h"
#include "stack.h"
#include "lispexecuter.h"

Func_prog::Func_prog(LispExecuter *executer):Function("prog",FSUBR),executer(executer)
{
}

Result Func_prog::run_(const Arguments & arguments)
{

    Arguments::const_iterator i;
    for (i = arguments.begin(); i != arguments.end(); i++)
        executer->functionHandler(i->getData());
    return Result(new AtomNilData());
}
