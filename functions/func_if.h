#ifndef FUNC_IF_H
#define FUNC_IF_H

#include "function.h"

class LispExecuter;

class Func_if : public Function
{
public:
    Func_if(LispExecuter * executer);
private:
    virtual Result run_(const Arguments &arguments);
    LispExecuter * executer;
};

#endif // FUNC_IF_H
