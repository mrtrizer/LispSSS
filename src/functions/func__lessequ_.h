#ifndef FUNC__LESSEQU__H
#define FUNC__LESSEQU__H

#include "function.h"

class Func__LessEqu_ : public Function
{
public:
    Func__LessEqu_();
    std::string getName() const {return "Less or equal";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
};

#endif // FUNC__LESSEQU__H
