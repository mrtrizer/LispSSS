#ifndef FUNC_NOTEQU_H
#define FUNC_NOTEQU_H

#include "function.h"

class Func__NotEqu_ : public Function
{
public:
    Func__NotEqu_();
private:
    virtual Result run_(const Arguments &arguments);
};

#endif // FUNC_NOTEQU_H
