#include "func_while.h"
#include "lispexecuter.h"
#include "listdata.h"
#include "atomnildata.h"

Result Func_while::run_(const Arguments &arguments, Memory *stack) const
{
    TEST_ARG(1,Data::LIST);
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
    return Result(new AtomNilData());
}
