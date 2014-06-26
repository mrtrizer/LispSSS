#ifndef FUNC_FUNC_H
#define FUNC_FUNC_H

#include "function.h"

class LispExecuter;

class Func_func : public Function
{
public:
    Func_func(LispExecuter *executer);
    std::string getName() const {return "func";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
    LispExecuter * executer;
};

#endif // FUNC_FUNC_H
