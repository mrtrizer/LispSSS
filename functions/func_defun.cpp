#include "func_defun.h"
#include "funccontroller.h"
#include "lispfunction.h"

Func_defun::Func_defun(FuncController * funcController, Stack * stack, LispExecuter * executer):
    Function("defun",FSUBR,3),funcController(funcController),stack(stack),executer(executer)
{
}

Result Func_defun::run_(const Arguments & arguments)
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
    funcController->setFunction(new LispFunction(name,FunctionType::EXPR,argCount,arguments[2].getData()->getClone(),
                                arguments[1].getData()->getClone(),executer,stack));
    return Result(new AtomNilData());
}
