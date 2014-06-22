#ifndef FUNC_PROG_H
#define FUNC_PROG_H

#include "function.h"

class Func_prog:public Function
{
public:
    Func_prog();
private:
    virtual Result run_(const Arguments & arguments);
};

#endif // FUNC_PROG_H
