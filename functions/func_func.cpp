#include "func_func.h"
#include "atomnildata.h"
#include "funcdata.h"
#include "lispfunction.h"
#include "lispnode.h"
#include "listdata.h"
#include "atomdata.h"

Func_func::Func_func(LispExecuter * executer):Function(FSUBR,2),executer(executer)
{
}

Result Func_func::run_(const Arguments & arguments, Memory *stack) const
{
    (void) stack;
    (void) arguments;
    //return Result(new AtomNilData());
    int argCount = 0;
    int minArgCount = 0;
    LispNode * tmp = ((ListData *)arguments[0].getData())->getRoot();
    while (tmp != 0)
    {
        if(tmp->data->getDataType() == Data::ATOM)
        {
            if (((AtomData *)tmp->data)->getName() == "...")
            {
                minArgCount = argCount;
                argCount = -1;
                break;
            }
            else
                argCount++;
        }
        else
            ERROR_MESSAGE ("All argument names must be atoms.");
        tmp = tmp->next;
    }
    return Result(new FuncData(new LispFunction(Function::EXPR,argCount,minArgCount,arguments[1].getData()->getClone(),
                               arguments[0].getData()->getClone(),executer),0));
}
