#include "func__power_.h"
#include "atomfloatdata.h"
#include "atomintdata.h"
#include "atomtdata.h"
#include "atomnildata.h"
#include "math.h"

Result Func__Power_::run_(const Arguments & arguments, Memory *stack) const
{
    (void)stack;
    double operand1;
    double operand2;
    if (arguments[0].getData()->getDataType() == Data::ATOM_FLOAT)
        operand1 = ((AtomFloatData *)arguments[0].getData())->getNum();
    else
    {
        TEST_ARG(0,Data::ATOM_INT);
        operand1 = ((AtomIntData *)arguments[0].getData())->getNum();
    }

    if (arguments[1].getData()->getDataType() == Data::ATOM_FLOAT)
        operand2 = ((AtomFloatData *)arguments[1].getData())->getNum();
    else
    {
        TEST_ARG(1,Data::ATOM_INT);
        operand2 = ((AtomIntData *)arguments[1].getData())->getNum();
    }
    return Result(new AtomFloatData(pow(operand1,operand2)));
}
