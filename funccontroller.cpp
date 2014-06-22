#include "funccontroller.h"
#include "func_defun.h"
#include "func___global.h"
#include "func__plus_.h"
#include "func__minus_.h"
#include "func__mul_.h"
#include "func__div_.h"
#include "func_print.h"
#include "func_if.h"
#include "func__equ_.h"
#include "func__notequ_.h"
#include "func_while.h"
#include "func_return.h"
#include "func_prog.h"
#include "func_setq.h"
#include "func_ask.h"
#include "message.h"

FuncController::FuncController(LispExecuter *executer, Stack * stack, std::ostream * out, std::istream * in):
    out(out),in(in),executer(executer),stack(stack)
{
    setFunction(new Func_defun(this,stack,executer));
    //setFunction(new Func___global(executer, stack));
    setFunction(new Func__plus_());
    setFunction(new Func__Minus_());
    setFunction(new Func__Mul_());
    setFunction(new Func__Div_());
    setFunction(new Func_print(out));
    setFunction(new Func_if(executer));
    setFunction(new Func__Equ_());
    setFunction(new Func__NotEqu_());
    setFunction(new Func_while(executer));
    setFunction(new Func_return());
    setFunction(new Func_prog(executer));
    setFunction(new Func_setq(stack,executer));
    setFunction(new Func_ask(out,in));
}

Function * FuncController::getFunction(std::string name)
{
    Function * result = functions[name];
    if (result == 0)
        throw Message("No functions with name :" + name + ".",0,0,Message::ERROR);
    return result;
}

void FuncController::setFunction(Function * function)
{
    functions.insert(FunctionItem(function->name,function));
}
