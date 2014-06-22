#ifndef VAR_H
#define VAR_H

#include "lispnode.h"
#include "value.h"

#include <string>
#include <map>

class Var
{
public:
    Var(const std::string & name, Data * data);
    Var();
    std::string name;
    Value value;
};

#endif // VAR_H
