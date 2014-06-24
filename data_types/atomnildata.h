#ifndef ATOMNILDATA_H
#define ATOMNILDATA_H

#include "data.h"

///@brief Represents nil atom
class AtomNilData:public Data
{
public:
    std::string toString() const {return std::string("nil");}
    DataType getDataType() const {return ATOM_NIL;}
    Data * getClone() const {return new AtomNilData(*this);}
    bool isEqual(const Data * data) const
    {
        if (data->getDataType() == ATOM_NIL)
            return true;
        return false;
    }
};

#endif // ATOMNILDATA_H
