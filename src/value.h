#ifndef VALUE_H
#define VALUE_H

#include "data.h"

///@brief I don't like smart pointers.
class Value
{
public:
    Value(Data * data = 0);
    Value(Value const & value){data = value.data->getClone();}
    Value & operator=(const Value & value)
    {
        if (data)
            delete data;
        if (value.data != 0)
            data = value.data->getClone();
        else
            data = 0;
        return *this;
    }

    ~Value(){if (data) delete data;}
    const Data * getData() const {return data;}
private:
    Data * data;
};

#endif // VALUE_H
