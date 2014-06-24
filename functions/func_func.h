#ifndef FUNC_FUNC_H
#define FUNC_FUNC_H

#include "function.h"

class Stack;

class Func_func : public Function
{
public:
    Func_func(Stack *stack);
private:
    virtual Result run_(const Arguments & arguments) const;
    Stack * stack;
};

#endif // FUNC_FUNC_H
