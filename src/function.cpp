#include "function.h"
#include "message.h"

Function::Function(FunctionType type, int argCount, int minArgCount):argCount(argCount),minArgCount(minArgCount)
{
    this->type = type;
}

Result Function::run(const Arguments & arguments, Memory * stack) const
{
    if (argCount > 0)
        if (arguments.size() != (unsigned char)argCount)
            ERROR_MESSAGE("Function " + this->getName() + " needs " + std::to_string(argCount) + " arguments.");
    if (arguments.size() < (unsigned char)minArgCount)
        ERROR_MESSAGE("Function " + this->getName() + " needs not less than " + std::to_string(minArgCount) + " arguments.");
    return run_(arguments,stack);
}
