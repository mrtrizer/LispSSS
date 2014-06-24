#include "atomintdata.h"
#include "atomfloatdata.h"

bool AtomIntData::isEqual(const Data * data) const
{
    if (data->getDataType() == ATOM_INT)
        return ((AtomIntData *)data)->num == num;
    if (data->getDataType() == ATOM_FLOAT)
        return ((AtomIntData *)data)->num == (float)num;
    return false;
}
