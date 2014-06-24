#include "func_while.h"
#include "lispexecuter.h"
#include "listdata.h"
#include "atomnildata.h"

Func_while::Func_while(LispExecuter * executer):Function("while",FSUBR,2),executer(executer)
{
}

Result Func_while::run_(const Arguments &arguments) const
{
    if (arguments[1].getData()->getDataType() == Data::LIST)
    {
        try
        {
            while (executer->functionHandler((ListData *)arguments[0].getData()).getData()->getDataType() == Data::ATOM_T)
                executer->functionHandler((ListData *)arguments[1].getData());
        }
        catch (return_exception & e)
        {
            return e.getResult();
        }
    }
    else
        ERROR_MESSAGE("Second argument must be LIST.");
    return Result(new AtomNilData());
}
