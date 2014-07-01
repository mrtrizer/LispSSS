#ifndef FUNC_ASK_H
#define FUNC_ASK_H

#include "function.h"

#include <iostream>

class Func_ask : public Function
{
public:
    Func_ask(std::ostream * out = 0, std::istream * in = 0):Function(SUBR,-1),in(in),out(out){}
    std::string getName() const {return "ask";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
    std::istream * in;
    std::ostream * out;
};

#endif // FUNC_ASK_H
