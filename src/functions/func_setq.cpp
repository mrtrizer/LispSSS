#include "func_setq.h"
#include "lispexecuter.h"
#include "atomdata.h"
#include "atomnildata.h"

Func_setq::Func_setq(LispExecuter *executer):Function(FSUBR,2),executer(executer)
{
}

Result Func_setq::run_(const Arguments & arguments, Memory *stack) const
{
    if (arguments[0].getData()->getDataType() == Data::ATOM)
    {
        AtomData * atom = (AtomData *)arguments[0].getData();
        Var var(atom->getName(),(Data *)executer->functionHandler(arguments[1].getData(),stack).getData()->getClone());
        stack->setVar(var);
        return Result(var.value);
    }
    else
        ERROR_MESSAGE("Function setq. First argument must be ATOM");
    return Result(new AtomNilData());
}
