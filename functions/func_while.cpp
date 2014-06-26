#include "func_while.h"
#include "lispexecuter.h"
#include "listdata.h"
#include "atomnildata.h"

Func_while::Func_while(LispExecuter * executer):Function(FSUBR,2),executer(executer)
{
}

Result Func_while::run_(const Arguments &arguments, Memory *stack) const
{
    if (arguments[1].getData()->getDataType() == Data::LIST)
    {
        while (executer->functionHandler((ListData *)arguments[0].getData(),stack).getData()->getDataType() == Data::ATOM_T)
        {
            try
            {
                executer->functionHandler((ListData *)arguments[1].getData(),stack);
            }
            catch (return_exception & e)
            {
                return e.getResult();
            }
            catch (continue_exception & e)
            {
                continue;
            }
        }
    }
    else
        ERROR_MESSAGE("Second argument must be LIST.");
    return Result(new AtomNilData());
}
