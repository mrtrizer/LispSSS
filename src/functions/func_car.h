#ifndef FUNC_CAR_H
#define FUNC_CAR_H

#include "function.h"

class Func_car : public Function
{
public:
    Func_car():Function(SUBR,1){}
    std::string getName() const {return "car";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
};

#endif // FUNC_CAR_H
