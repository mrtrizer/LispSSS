#ifndef FUNCDATA_H
#define FUNCDATA_H

#include "data.h"
#include "function.h"
#include "memory.h"

///@brief Function
class Function;
class Memory;
class FuncData:public Data
{
public:
    FuncData(const Function &func, Memory * mem);
    ~FuncData();
    std::string toString() const;
    const Function & getFunc() const {return func;}
    const Memory & getMem() const {return mem;}
    DataType getDataType() const {return FUNC;}
    Data * getClone() const;
    bool isEqual(const Data * data) const {(void)data; return false;}
private:
    const Function & func;
    Memory mem;
};

#endif // FUNCDATA_H
