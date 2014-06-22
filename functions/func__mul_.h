#ifndef FUNC__MUL__H
#define FUNC__MUL__H

#include "function.h"

class Func__Mul_ : public Function
{
public:
    Func__Mul_();
private:
    virtual Result run_(const Arguments & arguments);
};

#endif // FUNC__MUL__H
