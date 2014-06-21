#ifndef LISPNODE_H
#define LISPNODE_H

///@brief Один элемент синтаксического дерева.
class LispNode
{
public:
    LispNode():data(0),dataType(0),next(0){}
    void * data;
    unsigned char dataType;
    LispNode * next;
};

#endif // LISPNODE_H
