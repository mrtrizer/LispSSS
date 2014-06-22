#ifndef FUNC___GLOBAL_H
#define FUNC___GLOBAL_H

#include "function.h"

class Func___global : public Function
{
public:
    Func___global();
    virtual ~Func___global(){}
private:
    virtual Result run_(const Arguments & arguments);
};

#endif // FUNC___GLOBAL_H
