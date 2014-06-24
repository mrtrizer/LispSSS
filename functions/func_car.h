#ifndef FUNC_CAR_H
#define FUNC_CAR_H

#include "function.h"

class Func_car : public Function
{
public:
    Func_car();
private:
    virtual Result run_(const Arguments & arguments) const;
};

#endif // FUNC_CAR_H
