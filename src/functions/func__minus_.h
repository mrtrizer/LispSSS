#ifndef FUNC__MINUS__H
#define FUNC__MINUS__H

#include "function.h"

class Func__Minus_ : public Function
{
public:
    Func__Minus_();
    std::string getName() const{return "Minus";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__MINUS__H
