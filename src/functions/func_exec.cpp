#include "func_exec.h"
#include "lispexecuter.h"
#include "listdata.h"
#include "atomdata.h"
#include "atomnildata.h"
#include "funcdata.h"
#include "func_prog.h"
#include "memory.h"

Result Func_exec::run_(const Arguments & arguments, Memory *stack) const
{
    if (arguments.size() == 1)
        return executer->functionHandler(arguments[0].getData(),stack);
    else
    {
        TEST_ARG(1,Data::LIST);
        Memory localStack(0);
        std::vector<LispNode>::const_iterator i;
        ListData * listData = (ListData *)arguments[1].getData();
        for (i = listData->list.begin();i != listData->list.end(); i++)
        {
            if (i->data->getDataType() != Data::ATOM)
                ERROR_MESSAGE("All elements in the variable list must be ATOM.");
            localStack.setVar(stack->findVar(((AtomData*) i->data)->getName()));
        }
        localStack.setVar(Var("prog",new FuncData(new Func_prog(executer),0)));
        return executer->functionHandler(arguments[0].getData(),&localStack);
    }
    return Result(new AtomNilData());
}
