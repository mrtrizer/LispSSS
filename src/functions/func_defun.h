#ifndef FUNC_DEFUN_H
#define FUNC_DEFUN_H

#include "function.h"

class FuncController;
class Stack;
class LispExecuter;

class Func_defun : public Function
{
public:
    Func_defun(LispExecuter *executer);
    std::string getName() const {return "defun";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
    LispExecuter * executer;
};

#endif // FUNC_DEFUN_H
