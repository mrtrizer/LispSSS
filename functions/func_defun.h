#ifndef FUNC_DEFUN_H
#define FUNC_DEFUN_H

#include "function.h"

class Func_defun : public Function
{
public:
    Func_defun();
    virtual ~Func_defun(){}
private:
    virtual Result run_(const Arguments & arguments);
};

#endif // FUNC_DEFUN_H
