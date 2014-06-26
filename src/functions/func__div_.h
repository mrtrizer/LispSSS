#ifndef FUNC__DIV__H
#define FUNC__DIV__H

#include "function.h"

class Func__Div_ : public Function
{
public:
    Func__Div_();
    ///@brief Returns function name
    std::string getName() const{return "Div";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
};

#endif // FUNC__DIV__H
