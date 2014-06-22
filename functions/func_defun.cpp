#include "func_defun.h"

Func_defun::Func_defun():Function("defun",FSUBR,3)
{
}

Result Func_defun::run_(const Arguments & arguments)
{
    (void) arguments;
    return Result(new LispNode());
}
