#include "func_if.h"
#include "lispexecuter.h"
#include "listdata.h"
#include "atomnildata.h"

Func_if::Func_if(LispExecuter * executer):Function("if",FSUBR,2),executer(executer)
{
}

Result Func_if::run_(const Arguments & arguments) const
{
    Result result;
    if (arguments[0].getData()->getDataType() == Data::LIST)
        result = executer->functionHandler((ListData *)arguments[0].getData());
    else
        result = (Result)arguments[0];
    if (result.getData()->getDataType() == Data::ATOM_T)
        return executer->functionHandler((ListData *)arguments[1].getData());
    return Result(new AtomNilData());
}
