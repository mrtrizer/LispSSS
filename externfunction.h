#ifndef EXTERNFUNCTION_H
#define EXTERNFUNCTION_H

#include "function.h"

#include <vector>

class LispExecuter;
class Stack;

class ArgumentName
{
public:
    ArgumentName(std::string name, Data::DataType type):name(name),type(type){}
    std::string getName(){return name;}
    Data::DataType getType(){return type;}
private:
    std::string name;
    Data::DataType type;
};

class ExternFunction : public Function
{
public:
    ExternFunction(std::vector<ArgumentName>, LispExecuter * executer, void(*func)(void));
    std::string toString() const {return "Extern function";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
    std::vector<ArgumentName> args;
    void (* func)(void);
    LispExecuter * executer;
};

#endif // EXTERNFUNCTION_H
