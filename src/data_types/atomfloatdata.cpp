#include "atomfloatdata.h"
#include "atomintdata.h"

bool AtomFloatData::isEqual(const Data * data) const
{
    if (data->getDataType() == ATOM_FLOAT)
        return ((AtomFloatData *)data)->num == num;
    if (data->getDataType() == ATOM_INT)
        return (double)((AtomIntData *)data)->num == num;
    return false;
}
