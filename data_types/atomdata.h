#ifndef ATOMDATA_H
#define ATOMDATA_H

#include "data.h"

///@brief Represents atom
class AtomData:public Data
{
public:
    AtomData(const std::string & str){this->str = str;}
    std::string toString() const {return str;}
    DataType getDataType() const {return ATOM;}
    Data * getClone() const {return new AtomData(*this);}
    std::string getName() const {return str;}
    bool isEqual(const Data * data) const
    {
        if (data->getDataType() == ATOM)
            return ((AtomData *)data)->str == str;
        return false;
    }
private:
    std::string str;
};

#endif // ATOMDATA_H
