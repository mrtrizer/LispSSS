#ifndef FUNC__EQU__H
#define FUNC__EQU__H

#include "function.h"

class Func__Equ_ : public Function
{
public:
    Func__Equ_();
private:
    virtual Result run_(const Arguments &arguments) const;
};

#endif // FUNC__EQU__H
