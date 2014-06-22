#ifndef FUNC_WHILE_H
#define FUNC_WHILE_H

#include "function.h"

class LispExecuter;

class Func_while:public Function
{
public:
    class return_exception
    {
    public:
        return_exception(const Result & result):result(result){}
        Result getResult(){return result;}
    private:
        Result result;
    };
    Func_while(LispExecuter * executer);
private:
    virtual Result run_(const Arguments &arguments);
    LispExecuter * executer;
};

#endif // FUNC_WHILE_H
