#ifndef ATOMFLOATDATA_H
#define ATOMFLOATDATA_H

#include "data.h"

///@brief Represents float
class AtomFloatData:public Data
{
    friend class AtomIntData;
public:
    AtomFloatData(float num){this->num = num;}
    std::string toString() const {return std::to_string(num);}
    DataType getDataType() const {return ATOM_FLOAT;}
    Data * getClone() const {return new AtomFloatData(*this);}
    bool isEqual(const Data * data) const;
    float getNum() const {return num;}
private:
    float num;
};

#endif // ATOMFLOATDATA_H
