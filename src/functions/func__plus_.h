#ifndef FUNC__PLUS__H
#define FUNC__PLUS__H

#include "function.h"

class Func__Plus_ : public Function
{
public:
    Func__Plus_():Function(SUBR,-1,2){}
    std::string getName() const {return "Plus";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__PLUS__H
