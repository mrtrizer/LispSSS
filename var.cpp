#include "var.h"

Var::Var(const std::string & name, const LispNode & data)
{
    this->name = name;
    this->data = data;
}
