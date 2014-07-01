#include "func_setq.h"
#include "lispexecuter.h"
#include "atomdata.h"
#include "atomnildata.h"

Result Func_setq::run_(const Arguments & arguments, Memory *stack) const
{
    TEST_ARG(0,Data::ATOM);
    AtomData * atom = (AtomData *)arguments[0].getData();
    Var var(atom->getName(),(Data *)executer->functionHandler(arguments[1].getData(),stack).getData()->getClone());
    stack->setVar(var);
    return Result(var.value);
}
