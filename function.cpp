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
            throw Message("Function " + name + " needs " + std::to_string(argCount) + " arguments.",0,0,Message::ERROR);
    if (arguments.size() < (unsigned char)minArgCount)
        throw Message("Function " + name + " needs not less than " + std::to_string(minArgCount) + " arguments.",0,0,Message::ERROR);
    return run_(arguments);
}
