#ifndef FUNC_EXEC_H
#define FUNC_EXEC_H

#include "function.h"

class LispExecuter;

class Func_exec : public Function
{
public:
    Func_exec(LispExecuter *executer);
    std::string getName() const {return "exec";}
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const;
    LispExecuter * executer;
};

#endif // FUNC_EXEC_H
