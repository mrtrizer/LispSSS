#ifndef LISPFUNCTION_H
#define LISPFUNCTION_H

#include "function.h"

class LispExecuter;
class Stack;

class LispFunction : public Function
{
public:
    LispFunction(std::string name, FunctionType type, int argCount,
                 const Data * text, const Data * args, LispExecuter * executer, Stack * stack);
private:
    virtual Result run_(const Arguments &arguments) const;
    const Data * args;
    const Data * text;
    LispExecuter * executer;
    Stack * stack;
};

#endif // LISPFUNCTION_H
