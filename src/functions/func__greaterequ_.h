#ifndef FUNC__GREATEREQU__H
#define FUNC__GREATEREQU__H

#include "function.h"

class Func__GreaterEqu_ : public Function
{
public:
    Func__GreaterEqu_():Function(SUBR,2){}
    std::string getName() const {return "Greater or equal";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__GREATEREQU__H
