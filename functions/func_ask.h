#ifndef FUNC_ASK_H
#define FUNC_ASK_H

#include "function.h"

#include <iostream>

class Func_ask : public Function
{
public:
    Func_ask(std::ostream * out = 0, std::istream * in = 0);
private:
    virtual Result run_(const Arguments & arguments) const;
    std::istream * in;
    std::ostream * out;
};

#endif // FUNC_ASK_H
