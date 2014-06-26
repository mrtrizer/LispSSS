#ifndef LISPNODE_H
#define LISPNODE_H

#include <string>

class Data;

///@brief Один элемент синтаксического дерева.
class LispNode
{
public:
    LispNode();
    LispNode(Data * data);
    LispNode(const LispNode &node);
    ~LispNode();
    std::string toString();
    Data * data;
    LispNode * next;
private:
    std::string spaces(int n);
    std::string toString(LispNode *item, int n);
};



#endif // LISPNODE_H
