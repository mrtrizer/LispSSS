#include "func_exec.h"
#include "lispexecuter.h"
#include "listdata.h"
#include "atomdata.h"
#include "atomnildata.h"
#include "funcdata.h"
#include "func_prog.h"
#include "memory.h"

Func_exec::Func_exec(LispExecuter *executer):Function(SUBR,-1,1),executer(executer)
{
}

Result Func_exec::run_(const Arguments & arguments, Memory *stack) const
{
    if (arguments.size() == 1)
        return executer->functionHandler(arguments[0].getData(),stack);
    else
    {
        TEST_ARG(1,Data::LIST);
        Memory localStack(0);
        LispNode * tmp = ((ListData *)arguments[1].getData())->getRoot();
        while (tmp != 0)
        {
            if (tmp->data->getDataType() != Data::ATOM)
                ERROR_MESSAGE("All elements in the variable list must be ATOM.");
            localStack.setVar(stack->findVar(((AtomData*) tmp->data)->getName()));
            tmp = tmp->next;
        }
        localStack.setVar(Var("prog",new FuncData(new Func_prog(executer),0)));
        return executer->functionHandler(arguments[0].getData(),&localStack);
    }
    return Result(new AtomNilData());
}
