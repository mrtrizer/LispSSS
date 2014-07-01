#ifndef FUNC_QUOTE_H
#define FUNC_QUOTE_H

#include "function.h"

class Func_quote : public Function
{
public:
    Func_quote():Function(FSUBR,1){}
    std::string getName() const {return "quote";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
};

#endif // FUNC_QUOTE_H
