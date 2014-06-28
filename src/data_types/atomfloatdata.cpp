#include "atomfloatdata.h"
#include "atomintdata.h"
#include "math.h"

bool AtomFloatData::isEqual(const Data * data) const
{
    if (data->getDataType() == ATOM_FLOAT)
        return ((AtomFloatData *)data)->num == num;
    if (data->getDataType() == ATOM_INT)
        return (double)((AtomIntData *)data)->num == num;
    return false;
}

std::string AtomFloatData::toString() const
{
    double test;
    if (modf(num,&test) == 0.0)
        return std::to_string((int) test);
    return std::to_string(num);
}
