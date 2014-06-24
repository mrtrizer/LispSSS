#ifndef FUNC__LESS__H
#define FUNC__LESS__H

#include "function.h"

class Func__Less_ : public Function
{
public:
    Func__Less_();
    std::string getName() const {return "Less";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__LESS__H
