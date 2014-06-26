#ifndef FUNC_CDR_H
#define FUNC_CDR_H

#include "function.h"

class Func_cdr : public Function
{
public:
    Func_cdr();
    std::string getName() const {return "cdr";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
};

#endif // FUNC_CDR_H
