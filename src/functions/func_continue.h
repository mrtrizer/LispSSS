#ifndef FUNC_CONTINUE_H
#define FUNC_CONTINUE_H

#include "function.h"

class Func_continue : public Function
{
public:
    Func_continue():Function(SUBR){}
    std::string getName() const {return "continue";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
};

#endif // FUNC_CONTINUE_H
