#include "func_if.h"
#include "lispexecuter.h"
#include "listdata.h"
#include "atomnildata.h"
#include "atomdata.h"

Result Func_if::run_(const Arguments & arguments, Memory *stack) const
{
    Result result;
    if (arguments.size() > 2)
    {
        if (arguments.size() != 4)
            ERROR_MESSAGE("Function " + getName() + " needs 2 or 4 arguments.");
        if (arguments[2].getData()->getDataType() != Data::ATOM)
            ERROR_MESSAGE("Function " + getName() + " needs ATOM as 3th argument.");
        if (((AtomData *)arguments[2].getData())->getName() != "else")
            ERROR_MESSAGE("Function " + getName() + " needs \"else\" as 3th argument.");
    }
    result = executer->functionHandler((ListData *)arguments[0].getData(),stack);
    if (result.getData()->getDataType() == Data::ATOM_T)
        return executer->functionHandler(arguments[1].getData(),stack);
    else
        if (arguments.size() > 2)
            return executer->functionHandler(arguments[3].getData(),stack);
    return Result(new AtomNilData());
}
