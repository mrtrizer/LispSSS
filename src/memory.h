#ifndef MEMORY_H
#define MEMORY_H

#include "var.h"

///@brief This class represents an associative array, witch contains
/// variables in block and a pointer to the previous instance.
class Memory
{
public:
    Memory(Memory * prev);
    ///@brief Adds or changes variable into last block.
    void setVar(Var var);
    ///@brief Looking for a var with some name.
    Var findVar(std::string name);
    Memory * getPrev() const {return prev;}
private:
    ///@brief Pointer to prev memory block, or null
    Memory * prev;
    ///@brief Each block contains VarItem
    typedef std::map<std::string,Var> Block;
    ///@brief Each VarItem contains std::string as key and Var as field.
    typedef std::pair<std::string,Var> VarItem;
    Block block;
    ///@brief Looking for a var with some name and returns pointer.
    Var *findVarPointer(std::string name);
};

#endif // MEMORY_H
