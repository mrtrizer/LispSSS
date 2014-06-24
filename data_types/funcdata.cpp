#include "funcdata.h"

#include "funcdata.h"
#include "memory.h"
#include "function.h"

FuncData::FuncData(const Function & func, Memory * mem):func(func),mem(mem)
{
}

FuncData::~FuncData()
{

}

std::string FuncData::toString() const
{
    return func.toString();
}

Data * FuncData::getClone() const
{
    return new FuncData(func,mem.getPrev());
}

