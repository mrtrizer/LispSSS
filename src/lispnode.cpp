#include "lispnode.h"
#include "data.h"
#include "listdata.h"

#include <string>

LispNode::~LispNode()
{
    if (next) //FIXIT
        delete next;
    if (data)
        delete data;
}

LispNode::LispNode(LispNode const & node)
{
    if (node.data)
        this->data = node.data->getClone();
    else
        this->data = 0;
    if (node.next)
        this->next = new LispNode(*node.next);
    else
        this->next = 0;
    this->pos = node.pos;
}

std::string LispNode::toString()
{
    return toString(this,0);
}

std::string LispNode::spaces(int n)
{
    std::string str;
    for (int i = 0; i < n * 3; i++)
        str += ' ';
    return str;
}

std::string LispNode::toString(LispNode * item, int n)
{
    std::string str;
    if (item->data->getDataType() == Data::LIST)
    {
        LispNode * tmp = ((ListData *)item->data)->getRoot();
        str += spaces(n);
        str += "(\n";
        str += toString(tmp,n + 1);
        str += spaces(n);
        str += ")\n";
        if (item->next != 0)
            str += '\n' + item->next->toString(item->next,n);
    }
    else
    {
        str += spaces(n);
        str += item->data->toString();
        if (item->next != 0)
            str += '\n' + item->next->toString(item->next,n);
        else
            str += '\n';
    }
    return str;
}
