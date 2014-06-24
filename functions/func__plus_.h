#ifndef FUNC__PLUS__H
#define FUNC__PLUS__H

#include "function.h"

class Func__plus_ : public Function
{
public:
    Func__plus_();
private:
    virtual Result run_(const Arguments &arguments) const;
};

#endif // FUNC__PLUS__H
