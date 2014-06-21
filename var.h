#ifndef VAR_H
#define VAR_H

#include "lispnode.h"

#include <string>

class Var
{
public:
    enum VarType {INT, FLOAT, STRING, FUNCTION, OBJECT};
    Var(const std::string & name, const LispNode & data);
    Var(){}
    std::string name;
    LispNode data;
};

#endif // VAR_H
