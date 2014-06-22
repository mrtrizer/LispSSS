#include "func___global.h"

Func___global::Func___global(Stack *stack, LispExecuter * executer):
    Function("__global",SUBR),stack(stack),executer(executer)
{
}

Result Func___global::run_(const Arguments & arguments)
{
    (void) arguments;
    return Result(new AtomNilData());
}
