#ifndef DATA_H
#define DATA_H

#include <string.h>
#include "lispnode.h"

///@brief Represents data. Interface.
class Data
{
public:
    enum DataType {LIST = 1, ATOM = 2, ATOM_STR = 4, ATOM_INT = 8, ATOM_FLOAT = 16, ATOM_T = 32, ATOM_NIL = 64, FUNC = 128};

    virtual ~Data(){}
    ///@brief Returns a string representing data.
    virtual std::string toString() const = 0;
    ///@brief Returns one of types.
    virtual DataType getDataType() const = 0;
    ///@brief Returns clone of object.
    virtual Data * getClone() const = 0;
    ///@brief Returns true if this object equals another.
    virtual bool isEqual(const Data * data) const = 0;
};

#endif // DATA_H
