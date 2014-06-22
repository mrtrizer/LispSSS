#include "funccontroller.h"
#include "func_defun.h"
#include "func___global.h"
#include "func__plus_.h"
#include "message.h"

FuncController::FuncController()
{
    setFunction(new Func_defun());
    setFunction(new Func___global());
    setFunction(new Func__plus_());
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
