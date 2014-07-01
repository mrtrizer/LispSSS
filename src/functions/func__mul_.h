#ifndef FUNC__MUL__H
#define FUNC__MUL__H

#include "function.h"

class Func__Mul_ : public Function
{
public:
    Func__Mul_():Function(SUBR,-1,2){}
    std::string getName() const {return "Mul";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
};

#endif // FUNC__MUL__H
