#ifndef FUNC__NOT__H
#define FUNC__NOT__H

#include "function.h"

class Func__Not_ : public Function
{
public:
    Func__Not_();
    std::string getName() const {return "Not";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__NOT__H
