#ifndef FUNC__MINUS__H
#define FUNC__MINUS__H

#include "function.h"

class Func__Minus_ : public Function
{
public:
    Func__Minus_();
private:
    virtual Result run_(const Arguments &arguments) const;
};

#endif // FUNC__MINUS__H
