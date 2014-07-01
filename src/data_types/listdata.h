#ifndef LISTDATA_H
#define LISTDATA_H

#include "lispnode.h"
#include "data.h"
#include <vector>

///@brief Represents list
class ListData:public Data
{
public:
    ListData(){}
    std::string toString() const;
    DataType getDataType() const {return LIST;}
    Data * getClone() const
    {ListData * listData = new ListData();
        listData->list = list;
        return listData;}
    bool isEqual(const Data * data) const {(void)data; return false;}
    virtual unsigned int getSize() const {return 0;}
    std::vector<LispNode> list;
};

#endif // LISTDATA_H
