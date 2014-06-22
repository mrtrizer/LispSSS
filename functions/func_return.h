#ifndef FUNC_RETURN_H
#define FUNC_RETURN_H

#include "function.h"
#include "func_while.h"

class Func_return:public Function
{
public:
    Func_return();
private:
    virtual Result run_(const Arguments & arguments);
};

#endif // FUNC_RETURN_H
