#ifndef FUNC_PROG_H
#define FUNC_PROG_H

#include "function.h"

class Stack;
class LispExecuter;

class Func_prog:public Function
{
public:
    Func_prog(LispExecuter * executer);
private:
    virtual Result run_(const Arguments & arguments) const;
    LispExecuter * executer;
};

#endif // FUNC_PROG_H
