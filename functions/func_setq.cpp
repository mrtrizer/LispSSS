#include "func_setq.h"
#include "stack.h"
#include "lispexecuter.h"
#include "atomdata.h"
#include "atomnildata.h"

Func_setq::Func_setq(Stack * stack, LispExecuter *executer):Function("setq",FSUBR,2),stack(stack),executer(executer)
{
}

Result Func_setq::run_(const Arguments & arguments) const
{
    if (arguments[0].getData()->getDataType() == Data::ATOM)
    {
        AtomData * atom = (AtomData *)arguments[0].getData();
        Var var(atom->getName(),(Data *)executer->functionHandler(arguments[1].getData()).getData()->getClone());
        stack->setVar(var);
        return Result(var.value);
    }
    else
        ERROR_MESSAGE("First argument must be ATOM");
    return Result(new AtomNilData());
}
