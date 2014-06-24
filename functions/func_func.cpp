#include "func_func.h"
#include "atomnildata.h"

Func_func::Func_func(Stack * stack):Function("func",FSUBR,2),stack(stack)
{
}

Result Func_func::run_(const Arguments & arguments) const
{
    return Result(new AtomNilData());
    //return Result(new FuncData(arguments[0].getData()->getClone(),arguments[1].getData()->getClone()));
}
