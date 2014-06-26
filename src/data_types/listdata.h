#ifndef LISTDATA_H
#define LISTDATA_H

#include "lispnode.h"
#include "data.h"

///@brief Represents list
class ListData:public Data
{
public:
    ListData(LispNode * node){this->firstNode = node;}
    ~ListData(){delete firstNode;}
    std::string toString() const {return firstNode->toString();}
    LispNode * getRoot() const {return firstNode;}
    DataType getDataType() const {return LIST;}
    Data * getClone() const {return new ListData(new LispNode(*firstNode));}
    bool isEqual(const Data * data) const {(void)data; return false;}
private:
    LispNode * firstNode;
};

#endif // LISTDATA_H
