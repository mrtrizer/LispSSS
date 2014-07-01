#include "lispnode.h"
#include "data.h"
#include "listdata.h"

#include <string>

LispNode::~LispNode()
{
    if (data)
        delete data;
}

LispNode::LispNode(LispNode const & node)
{
    if (node.data)
        this->data = node.data->getClone();
    else
        this->data = 0;
    this->pos = node.pos;
}

std::string LispNode::toString() const
{
    return toString(0);
}

std::string LispNode::spaces(int n)
{
    std::string str;
    for (int i = 0; i < n * 3; i++)
        str += ' ';
    return str;
}

std::string LispNode::toString(int n) const
{
    std::string str;
    if (data->getDataType() == Data::LIST)
    {
        str += spaces(n) + "(\n";
        std::vector<LispNode>::iterator i;
        for (i = ((ListData *)data)->list.begin(); i != ((ListData *)data)->list.end(); i++)
            str += spaces(n) + i->toString() + "\n";
        str += ")\n";
    }
    else
        str += spaces(n) + data->toString();
    return str;
}
