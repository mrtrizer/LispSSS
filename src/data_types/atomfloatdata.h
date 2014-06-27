#ifndef ATOMFLOATDATA_H
#define ATOMFLOATDATA_H

#include "data.h"

///@brief Represents double
class AtomFloatData:public Data
{
    friend class AtomIntData;
public:
    AtomFloatData(double num){this->num = num;}
    virtual unsigned int getSize() const {return sizeof(num);}
    std::string toString() const {return std::to_string(num);}
    DataType getDataType() const {return ATOM_FLOAT;}
    Data * getClone() const {return new AtomFloatData(*this);}
    bool isEqual(const Data * data) const;
    double getNum() const {return num;}
private:
    double num;
};

#endif // ATOMFLOATDATA_H
