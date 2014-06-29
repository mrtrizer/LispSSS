#ifndef LISPNODE_H
#define LISPNODE_H

#include <string>
#include "pos.h"

class Data;

///@brief Один элемент синтаксического дерева.
class LispNode
{
public:
    LispNode(const Pos & pos):data(0),next(0),pos(pos){}
    LispNode(Data * data, const Pos & pos):data(data),next(0),pos(pos){}
    LispNode(Data * data):data(data),next(0){}
    LispNode(const LispNode &node);
    LispNode():data(0),next(0){}
    ~LispNode();
    const Pos & getPos()const {return pos;}
    std::string toString();
    Data * data;
    LispNode * next;
private:
    std::string spaces(int n);
    std::string toString(LispNode *item, int n);
    int line;
    Pos pos;
};



#endif // LISPNODE_H
