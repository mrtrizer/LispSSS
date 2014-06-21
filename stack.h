#ifndef STACK_H
#define STACK_H

#include "var.h"

#include <string>
#include <stack>
#include <map>

class Message;

class Stack
{
public:
    Stack();
    ///@brief Add block into stack. All variables added after blockPush will removed after blockPop
    void blockPush();
    ///@brief Removes all variables in block.
    void blockPop();
    ///@brief Adds or changes variable into last block.
    void setVar(Var var);
    ///@brief Looking for a var with some name.
    Var findVar(std::string name);
private:
    ///@brief Each block contains VarItem
    typedef std::map<std::string,Var> Block;
    ///@brief Each VarItem contains std::string as key and Var as field.
    typedef std::pair<std::string,Var> VarItem;
    ///@brief The stack consists of Blocks
    std::stack<Block> blockStack;
};

#endif // STACK_H
