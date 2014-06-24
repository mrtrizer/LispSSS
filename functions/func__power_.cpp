#include "func__power_.h"
#include "atomfloatdata.h"
#include "atomintdata.h"
#include "atomtdata.h"
#include "atomnildata.h"
#include "math.h"

Func__Power_::Func__Power_():Function(SUBR,2)
{
}

Result Func__Power_::run_(const Arguments & arguments, Memory *stack) const
{
    (void)stack;
    float operand1;
    float operand2;
    if (arguments[0].getData()->getDataType() == Data::ATOM_FLOAT)
        operand1 = ((AtomFloatData *)arguments[0].getData())->getNum();
    else
        if (arguments[0].getData()->getDataType() == Data::ATOM_INT)
            operand1 = ((AtomIntData *)arguments[0].getData())->getNum();
        else
            ERROR_MESSAGE("First operand must be INT or FLOAT");

    if (arguments[1].getData()->getDataType() == Data::ATOM_FLOAT)
        operand2 = ((AtomFloatData *)arguments[1].getData())->getNum();
    else
        if (arguments[1].getData()->getDataType() == Data::ATOM_INT)
            operand2 = ((AtomIntData *)arguments[1].getData())->getNum();
        else
            ERROR_MESSAGE("Second operand must be INT or FLOAT");

    return Result(new AtomFloatData(pow(operand1,operand2)));
}
