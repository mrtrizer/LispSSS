#include "listdata.h"

std::string ListData::toString() const
{
    std::string result;
    std::vector<LispNode>::const_iterator i;
    for (i = list.begin(); i != list.end(); i++)
        result += i->toString() + "\n";
    return result;
}
