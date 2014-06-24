#ifndef FUNC___GLOBAL_H
#define FUNC___GLOBAL_H

#include "function.h"

class Stack;
class LispExecuter;

class Func___global : public Function
{
public:
    Func___global(Stack *stack, LispExecuter * executer);
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
    Stack * stack;
    LispExecuter * executer;
};

#endif // FUNC___GLOBAL_H
