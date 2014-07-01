#ifndef FUNC_PRINT_H
#define FUNC_PRINT_H

#include "function.h"

#include <iostream>

class Func_print : public Function
{
public:
    Func_print(std::ostream * out = 0):Function(SUBR,-1,1),out(out){}
    std::string getName() const {return "print";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
    std::ostream * out;
};

#endif // FUNC_PRINT_H
