#ifndef VALUE_H
#define VALUE_H

#include "lispnode.h"

///@brief I don't like smart pointers.
class Value
{
public:
    Value(Data * data);
    Value(Value const & value){data = value.data->getClone();}
    ~Value(){delete data;}
    const Data * getData() const {return data;}
private:
    Data * data;
};

#endif // VALUE_H
