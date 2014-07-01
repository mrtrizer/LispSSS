#include "func_quote.h"
#include "atomnildata.h"

Result Func_quote::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;
    return Result(arguments[0].getData()->getClone());
}
