#ifndef FUNC_SIZE_H
#define FUNC_SIZE_H

#include "function.h"

class Func_size : public Function
{
public:
    Func_size():Function(SUBR,1){}
    std::string getName() const {return "size";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
};

#endif // FUNC_SIZE_H
