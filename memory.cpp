#include "memory.h"
#include "message.h"
#include <assert.h>

Memory::Memory(Memory * prev)
{
    this->prev = prev;
}

void Memory::setVar(Var var)
{
    assert(var.name.size() > 0);
    if (block.find(var.name) == block.end())
        block.insert(VarItem(var.name,var));
    else
        block[var.name] = var;
}

Var Memory::findVar(std::string name)
{
    assert(name.size() > 0);
    if (block.find(name) == block.end())
        return block[name];
    else
    {
        if (prev != 0)
            return prev->findVar(name);
        else
            ERROR_MESSAGE("Can't find variable with name " + name);
    }
}
