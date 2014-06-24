#ifndef FUNC__DIV__H
#define FUNC__DIV__H

#include "function.h"

class Func__Div_ : public Function
{
public:
    Func__Div_();
private:
    virtual Result run_(const Arguments & arguments) const;
};

#endif // FUNC__DIV__H
