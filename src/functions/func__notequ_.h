#ifndef FUNC_NOTEQU_H
#define FUNC_NOTEQU_H

#include "function.h"

class Func__NotEqu_ : public Function
{
public:
    Func__NotEqu_():Function(SUBR,-1,2){}
    std::string getName() const {return "Not equal";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC_NOTEQU_H
