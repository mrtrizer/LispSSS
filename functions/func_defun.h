#ifndef FUNC_DEFUN_H
#define FUNC_DEFUN_H

#include "function.h"

class FuncController;
class Stack;
class LispExecuter;

class Func_defun : public Function
{
public:
    Func_defun(FuncController *funcController, Stack *stack, LispExecuter *executer);
private:
    virtual Result run_(const Arguments & arguments);
    FuncController * funcController;
    Stack * stack;
    LispExecuter * executer;
};

#endif // FUNC_DEFUN_H
