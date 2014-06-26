#include "func_exec.h"
#include "lispexecuter.h"

Func_exec::Func_exec(LispExecuter *executer):Function(SUBR,1),executer(executer)
{
}

Result Func_exec::run_(const Arguments & arguments, Memory *stack) const
{
    return executer->functionHandler(arguments[0].getData(),stack);
}
