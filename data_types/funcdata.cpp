#include "funcdata.h"

#include "funcdata.h"
#include "memory.h"
#include "function.h"

FuncData::FuncData(Function * func, Memory * mem):func(func)
{
    this->mem = new Memory(mem);
}

FuncData::~FuncData()
{
    delete mem;
}

std::string FuncData::toString() const
{
    return func->toString();
}

Data * FuncData::getClone() const
{
    return new FuncData(func,mem->getPrev());
}

