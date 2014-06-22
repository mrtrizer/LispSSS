#include "func_while.h"
#include "lispexecuter.h"

Func_while::Func_while(LispExecuter * executer):Function("while",FSUBR,2),executer(executer)
{
}

Result Func_while::run_(const Arguments &arguments)
{
    Result result;
    if (arguments[0].getData()->getDataType() == Data::LIST)
        result = executer->functionHandler((ListData *)arguments[0].getData());
    else
        result = (Result)arguments[0];
    if (arguments[1].getData()->getDataType() == Data::LIST)
    {
        try
        {
            while (1)
                if (result.getData()->getDataType() == Data::ATOM_T)
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
