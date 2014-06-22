#include "lispnode.h"

#include <string>

LispNode::LispNode():data(0),dataType(ATOM_NIL),next(0)
{

}

LispNode::~LispNode()
{
    //if (next) //FIXIT
    //    delete next;
    //if (data)
    //    delete data;
}

std::string LispNode::toString()
{
    return toString(this,0);
}

std::string LispNode::toString(LispNode * item, int n)
{
    std::string str;
    switch (item->dataType)
    {
        case LispNode::ATOM_T:
        str += "T\n";
        break;
        case LispNode::ATOM_NIL:
        str += "nil\n";
        break;
        case LispNode::ATOM:
            str += ((char *)item->data);
            str += ('\n');
        break;
        case LispNode::ATOM_STR:
            str += ('\"');
            str += ((char *)item->data);
            str += ('\"');
            str += ('\n');
        break;
        case LispNode::ATOM_INT:
            str += (std::to_string(*((int *)item->data)));
            str += ('\n');
        break;
        case LispNode::ATOM_FLOAT:
            str += (std::to_string(*((double *)item->data)));
            str += ('\n');
        break;
        case LispNode::LIST:
            LispNode * tmp = (LispNode *)item->data;
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
        break;
    }
    return str;
}
