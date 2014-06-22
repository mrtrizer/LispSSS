#ifndef FUNC_SETQ_H
#define FUNC_SETQ_H

#include "function.h"

class Stack;
class LispExecuter;

class Func_setq : public Function
{
public:
    Func_setq(Stack * stack, LispExecuter * executer);
private:
    virtual Result run_(const Arguments & arguments);
    Stack * stack;
    LispExecuter * executer;
};

#endif // FUNC_SETQ_H
