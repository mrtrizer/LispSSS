#ifndef FUNC_PARSE_H
#define FUNC_PARSE_H

#include "function.h"

class Func_parse : public Function
{
public:
    Func_parse():Function(Function::SUBR,1){}
    std::string getName() const {return "parse";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC_PARSE_H
