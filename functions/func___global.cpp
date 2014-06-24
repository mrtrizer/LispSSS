#include "func___global.h"
#include "atomnildata.h"

Func___global::Func___global(Stack *stack, LispExecuter * executer):
    Function(SUBR),stack(stack),executer(executer)
{
}

Result Func___global::run_(const Arguments & arguments, Memory *stack) const
{
    (void) arguments;
    (void) stack;
    return Result(new AtomNilData());
}
