#ifndef FUNC__GREATER__H
#define FUNC__GREATER__H

#include "function.h"

class Func__Greater_ : public Function
{
public:
    Func__Greater_():Function(SUBR,2){}
    std::string getName() const {return "Greater";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__GREATER__H
