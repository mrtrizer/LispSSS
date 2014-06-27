#ifndef ATOMTDATA_H
#define ATOMTDATA_H

#include "data.h"

///@brief Represents true atom
class AtomTData:public Data
{
public:
    std::string toString() const {return std::string("T");}
    DataType getDataType() const {return ATOM_T;}
    Data * getClone() const {return new AtomTData(*this);}
    bool isEqual(const Data * data) const
    {
        if (data->getDataType() == ATOM_T)
            return true;
        return false;
    }
    virtual unsigned int getSize() const {return sizeof(bool);}
};

#endif // ATOMTDATA_H
