#include "func_continue.h"
#include "func_while.h"
#include "atomnildata.h"

Result Func_continue::run_(const Arguments & arguments, Memory *stack) const
{
    (void) stack;
    (void) arguments;
    throw Func_while::continue_exception();
    return Result(new AtomNilData());
}
