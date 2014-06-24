#include "lispfunction.h"
#include "lispexecuter.h"
#include "stack.h"
#include "func_while.h"
#include "listdata.h"
#include "atomdata.h"

#include <vector>

LispFunction::LispFunction(std::string name, FunctionType type, int argCount,
        const Data * text, const Data * args, LispExecuter * executer, Stack *stack):Function(name,type,argCount)
{
    this->executer = executer;
    this->stack = stack;
    this->args = args;
    this->text = text;
}

Result LispFunction::run_(const Arguments &arguments) const
{
    stack->blockPush();
    std::vector <std::string> names;
    LispNode * tmp = ((ListData *)args)->getRoot();
    while (tmp != 0)
    {
        names.push_back(((AtomData*)tmp->data)->getName());
        tmp = tmp->next;
    }
    if (names.size() != arguments.size())
        ERROR_MESSAGE("This function needs " + std::to_string(names.size()) + " arguments");
    for (unsigned int i = 0; i < names.size(); i++)
        stack->setVar(Var(names[i],(Data *)arguments[i].getData()->getClone()));
    Result result;
    try
    {
        result = executer->functionHandler(text);
    }
    catch (Func_while::return_exception & e)
    {
        result = e.getResult();
    }

    stack->blockPop();
    return result;
}
