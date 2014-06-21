#ifndef LISPNODE_H
#define LISPNODE_H

#include <string>

///@brief Один элемент синтаксического дерева.
class LispNode
{
public:
    enum NodeType {LIST = 0, ATOM = 1, ATOM_STR = 2, ATOM_INT = 3, ATOM_FLOAT = 4, ATOM_T = 5, ATOM_NIL = 6};

    LispNode():data(0),dataType(ATOM_NIL),next(0){}
    std::string toString();
    void * data;
    NodeType dataType;
    LispNode * next;
private:
    std::string toString(LispNode * item, int n);
};

#endif // LISPNODE_H
