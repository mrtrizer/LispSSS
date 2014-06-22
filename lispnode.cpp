#include "lispnode.h"

#include <string>

LispNode::LispNode():data(0),next(0)
{

}

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
}

std::string LispNode::toString()
{
    return toString(this,0);
}

std::string LispNode::toString(LispNode * item, int n)
{
    std::string str;
    if (item->data->getDataType() == Data::LIST)
    {
        LispNode * tmp = ((ListData *)item->data)->getRoot();
        str += "(\n";
        while (tmp != 0)
        {
            for (int i = 0; i < n + 1; i++)
                str += "  ";
            str += ((char)' ');
            str += (' ');
            str += toString(tmp,n + 1);
            tmp = tmp->next;
        }
        for (int i = 0; i < n + 1; i++)
            str += "  ";
        str += ")\n";
    }
    else
        str = item->data->toString() + '\n';
    return str;
}
