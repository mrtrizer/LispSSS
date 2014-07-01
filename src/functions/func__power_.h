#ifndef FUNC__POWER__H
#define FUNC__POWER__H

#include "function.h"

class Func__Power_ : public Function
{
public:
    Func__Power_():Function(SUBR,2){}
    std::string getName() const {return "Power";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__POWER__H
