#ifndef ATOMINTDATA_H
#define ATOMINTDATA_H

#include "data.h"

///@brief Represents integer
class AtomIntData:public Data
{
    friend class AtomFloatData;
public:
    AtomIntData(int num){this->num = num;}
    virtual unsigned int getSize() const {return sizeof(num);}
    std::string toString() const {return std::to_string(num);}
    DataType getDataType() const {return ATOM_INT;}
    Data * getClone() const {return new AtomIntData(*this);}
    bool isEqual(const Data * data) const;
    int getNum() const {return num;}
private:
    int num;
};

#endif // ATOMINTDATA_H
