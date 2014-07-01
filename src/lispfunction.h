#ifndef LISPFUNCTION_H
#define LISPFUNCTION_H

#include "function.h"

class LispExecuter;
class Stack;
class ListData;

class LispFunction : public Function
{
public:
    LispFunction(FunctionType type, int argCount, int minArgCount,
                 const Data * text, const ListData * args, LispExecuter * executer);
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
    const ListData * args;
    const Data * text;
    LispExecuter * executer;
    int argCount;
    int minArgCount;
};

#endif // LISPFUNCTION_H
