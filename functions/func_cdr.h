#ifndef FUNC_CDR_H
#define FUNC_CDR_H

#include "function.h"

class Func_cdr : public Function
{
public:
    Func_cdr();
private:
    virtual Result run_(const Arguments & arguments) const;
};

#endif // FUNC_CDR_H
