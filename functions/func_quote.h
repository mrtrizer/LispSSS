#ifndef FUNC_QUOTE_H
#define FUNC_QUOTE_H

#include "function.h"

class Func_quote : public Function
{
public:
    Func_quote();
private:
    virtual Result run_(const Arguments & arguments);
};

#endif // FUNC_QUOTE_H
