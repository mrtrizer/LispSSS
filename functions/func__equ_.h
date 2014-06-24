#ifndef FUNC__EQU__H
#define FUNC__EQU__H

#include "function.h"

class Func__Equ_ : public Function
{
public:
    Func__Equ_();
    std::string getName() const{return "Equ";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__EQU__H
