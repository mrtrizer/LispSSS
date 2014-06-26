#ifndef FUNC_SETQ_H
#define FUNC_SETQ_H

#include "function.h"

class Stack;
class LispExecuter;

class Func_setq : public Function
{
public:
    Func_setq(LispExecuter * executer);
    std::string getName() const {return "setq";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
    LispExecuter * executer;
};

#endif // FUNC_SETQ_H
