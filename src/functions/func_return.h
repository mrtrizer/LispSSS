#ifndef FUNC_RETURN_H
#define FUNC_RETURN_H

#include "function.h"
#include "func_while.h"

class Func_return:public Function
{
public:
    Func_return():Function(SUBR,1){}
    std::string getName() const {return "return";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
};

#endif // FUNC_RETURN_H
