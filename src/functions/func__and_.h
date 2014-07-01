#ifndef FUNC__AND__H
#define FUNC__AND__H

#include "function.h"

class Func__And_ : public Function
{
public:
    Func__And_():Function(SUBR,2){}
    std::string getName() const {return "And";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__AND__H
