#include "lispexecuter.h"
#include "lispstring.h"
#include "lispnode.h"
#include "function.h"
#include "lispfunction.h"
#include "listdata.h"
#include "atomdata.h"
#include "memory.h"
#include "funcdata.h"

//Standart functions:
#include "func__plus_.h"
#include "func__minus_.h"
#include "func__div_.h"
#include "func__mul_.h"
#include "func_setq.h"
#include "func_prog.h"
#include "func_quote.h"
#include "func__equ_.h"
#include "func__notequ_.h"
#include "func_ask.h"
#include "func_car.h"
#include "func_cdr.h"
#include "func_defun.h"
#include "func_if.h"
#include "func_print.h"
#include "func_return.h"
#include "func_while.h"
#include "func_func.h"


#include <assert.h>

LispExecuter::LispExecuter(LispString * lispString, std::ostream * errout,
                           std::ostream * out, std::istream * in)
{
    assert(lispString != 0);
    this->lispString = lispString;
    this->in = in;
    this->out = out;
    this->errout = errout;
}

void LispExecuter::run()
{
    if (!lispString->isValid())
        return;
    try
    {
        Memory global(0);
        global.setVar(Var("+",new FuncData (new Func__Plus_(),0)));
        global.setVar(Var("-",new FuncData (new Func__Minus_(),0)));
        global.setVar(Var("*",new FuncData (new Func__Mul_(),0)));
        global.setVar(Var("/",new FuncData (new Func__Div_(),0)));
        global.setVar(Var("setq",new FuncData (new Func_setq(this),0)));
        global.setVar(Var("prog",new FuncData(new Func_prog(this),0)));
        global.setVar(Var("quote",new FuncData(new Func_quote(),0)));
        global.setVar(Var("while",new FuncData(new Func_while(this),0)));
        global.setVar(Var("return",new FuncData(new Func_return(),0)));
        global.setVar(Var("if",new FuncData(new Func_if(this),0)));
        global.setVar(Var("==",new FuncData(new Func__Equ_(),0)));
        global.setVar(Var("!=",new FuncData(new Func__NotEqu_(),0)));
        global.setVar(Var("cdr",new FuncData(new Func_cdr(),0)));
        global.setVar(Var("car",new FuncData(new Func_car(),0)));
        global.setVar(Var("ask",new FuncData(new Func_ask(out,in),0)));
        global.setVar(Var("print",new FuncData(new Func_print(out),0)));
        global.setVar(Var("func",new FuncData(new Func_func(this),0)));

        *errout << "Script out: " << functionHandler(lispString->getRoot()->data,&global).getData()->toString();
    }
    catch (Message & m)
    {
        *errout << m.toString();
    }
}

Result LispExecuter::functionHandler(const Data * data, Memory * stack)
{
    if (data->getDataType() == Data::LIST)
    {
        ListData * listData = (ListData *)data;
        if (listData->getRoot()->data->getDataType() & (Data::ATOM | Data::LIST))
        {
            Result funcId = functionHandler(listData->getRoot()->data,stack);
            if (funcId.getData()->getDataType() == Data::FUNC)
            {
                FuncData * func = (FuncData *)funcId.getData();
                Arguments arguments;
                switch (func->getFunc()->type)
                {
                    case Function::EXPR:
                    case Function::SUBR:
                    {

                        LispNode * tmp = listData->getRoot()->next;
                        while (tmp != 0)
                        {
                            arguments.push_back((Value)functionHandler(tmp->data,stack));
                            tmp = tmp->next;
                        }

                        break;
                    }
                    case Function::MACRO:
                    case Function::FEXPR:
                    case Function::FSUBR:
                    {
                        arguments = Arguments::fromLispNode(listData->getRoot()->next);

                        break;
                    }
                }
                if (func->getMem()->getPrev() == 0)
                    return func->getFunc()->run(arguments,stack);
                else
                    return func->getFunc()->run(arguments,func->getMem());
            }
            else
                ERROR_MESSAGE("Function " + funcId.getData()->toString() + " not defined!");
        }
    }
    if (data->getDataType() == Data::ATOM)
        return (Result)stack->findVar(((AtomData *)data)->getName()).value;
    return Result(data->getClone());
}
