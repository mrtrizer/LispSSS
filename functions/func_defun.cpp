#include "func_defun.h"
#include "lispfunction.h"
#include "listdata.h"
#include "atomdata.h"
#include "atomnildata.h"
#include "funcdata.h"

Func_defun::Func_defun(LispExecuter * executer):Function(FSUBR,3),executer(executer)
{
}

Result Func_defun::run_(const Arguments & arguments, Memory *stack) const
{
    int argCount = 0;
    LispNode * tmp = ((ListData *)arguments[1].getData())->getRoot();
    while (tmp != 0)
    {
        argCount++;
        tmp = tmp->next;
    }
    Arguments::const_iterator i;
    std::string name = ((AtomData *)arguments[0].getData())->getName();
    stack->setVar(Var(name,new FuncData(new LispFunction(FunctionType::EXPR,argCount,0,arguments[2].getData()->getClone(),
                                        arguments[1].getData()->getClone(),executer),stack)));
    return Result(new AtomNilData());
}
