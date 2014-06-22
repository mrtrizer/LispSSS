#include "function.h"
#include "message.h"

Function::Function(const std::string &name, FunctionType type, int argCount, int minArgCount):argCount(argCount),minArgCount(minArgCount)
{
    this->name = name;
    this->type = type;
}

Result Function::run(const Arguments & arguments)
{
    if (argCount > 0)
        if (arguments.size() != (unsigned char)argCount)
            ERROR_MESSAGE("Function " + name + " needs " + std::to_string(argCount) + " arguments.");
    if (arguments.size() < (unsigned char)minArgCount)
        ERROR_MESSAGE("Function " + name + " needs not less than " + std::to_string(minArgCount) + " arguments.");
    return run_(arguments);
}

Arguments Arguments::fromLispNode(LispNode *node)
{
    Arguments result;
    while (node != 0)
    {
        result.push_back(Value(node->data->getClone()));
        node = node->next;
    }
    return result;
}
