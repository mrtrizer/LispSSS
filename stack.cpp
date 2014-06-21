#include "stack.h"

#include <assert.h>

Stack::Stack()
{
}

void Stack::blockPush()
{
    blockStack.push(Block());
}

void Stack::blockPop()
{
    assert(blockStack.size() > 0);
    blockStack.pop();
}

void Stack::setVar(Var var)
{
    assert(var.name.size() > 0);
    blockStack.top().insert(VarItem(var.name,var));
}

Var Stack::findVar(std::string name)
{
    assert(name.size() > 0);
    return blockStack.top()[name];
}
