#include "func_defun.h"
#include "lispfunction.h"
#include "listdata.h"
#include "atomdata.h"
#include "atomnildata.h"
#include "funcdata.h"

Result Func_defun::run_(const Arguments & arguments, Memory *stack) const
{
    int argCount = 0;
    argCount = ((ListData *)arguments[1].getData())->list.size();
    Arguments::const_iterator i;
    std::string name = ((AtomData *)arguments[0].getData())->getName();
    stack->setVar(Var(name,new FuncData(new LispFunction(FunctionType::EXPR,argCount,0,arguments[2].getData()->getClone(),
                                        (ListData*)arguments[1].getData()->getClone(),executer),stack)));
    return Result(new AtomNilData());
}
