#include "var.h"
#include "lispnode.h"
#include "atomnildata.h"

Var::Var(const std::string & name, Data * data):name(name),value(data)
{

}

Var::Var():value(new AtomNilData())
{

}
