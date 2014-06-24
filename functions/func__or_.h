#ifndef FUNC__OR__H
#define FUNC__OR__H

#include "function.h"

class Func__Or_ : public Function
{
public:
    Func__Or_();
    std::string getName() const {return "Or";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__OR__H
