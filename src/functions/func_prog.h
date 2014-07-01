#ifndef FUNC_PROG_H
#define FUNC_PROG_H

#include "function.h"

class Stack;
class LispExecuter;

class Func_prog:public Function
{
public:
    Func_prog(LispExecuter * executer):Function(FSUBR),executer(executer){}
    std::string getName() const {return "prog";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
    LispExecuter * executer;
};

#endif // FUNC_PROG_H
