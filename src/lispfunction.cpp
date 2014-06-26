#include "lispfunction.h"
#include "lispexecuter.h"
#include "func_while.h"
#include "listdata.h"
#include "atomdata.h"
#include "lispnode.h"

#include <vector>

LispFunction::LispFunction(FunctionType type, int argCount, int minArgCount,
        const Data * text, const Data * args, LispExecuter * executer):Function(type,argCount)
{
    this->executer = executer;
    this->args = args;
    this->text = text;
    this->argCount = argCount;
    this->minArgCount = minArgCount;
}

Result LispFunction::run_(const Arguments &arguments, Memory *stack) const
{
    std::vector <std::string> names;
    LispNode * tmp = ((ListData *)args)->getRoot();
    while (tmp != 0)
    {
        names.push_back(((AtomData*)tmp->data)->getName());
        tmp = tmp->next;
    }
    if (argCount != -1)
        if (argCount != (int)arguments.size())
            ERROR_MESSAGE("This function needs " + std::to_string(names.size()) + " arguments");
    if ((int)arguments.size() < minArgCount)
        ERROR_MESSAGE("This function needs not less than " + std::to_string(names.size()) + " arguments");
    for (unsigned int i = 0; i < names.size(); i++)
        stack->setVar(Var(names[i],(Data *)arguments[i].getData()->getClone()));
    if ((argCount == -1) && (minArgCount < (int)arguments.size()))
    {
        LispNode * start = 0;
        LispNode * cur = 0;
        for (unsigned int i = minArgCount; i < arguments.size(); i++)
        {
            if (start == 0)
                cur = start = new LispNode(arguments[i].getData()->getClone());
            else
                cur = cur->next = new LispNode(arguments[i].getData()->getClone());
        }
        stack->setVar(Var("_args_",new ListData(start)));
    }
    Result result;
    try
    {
        result = executer->functionHandler(text,stack);
    }
    catch (Func_while::return_exception & e)
    {
        result = e.getResult();
    }

    return result;
}
