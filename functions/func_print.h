#ifndef FUNC_PRINT_H
#define FUNC_PRINT_H

#include "function.h"

#include <iostream>

class Func_print : public Function
{
public:
    Func_print(std::ostream * out = 0);
private:
    virtual Result run_(const Arguments &arguments);
    std::ostream * out;
};

#endif // FUNC_PRINT_H
