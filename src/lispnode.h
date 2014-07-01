#ifndef LISPNODE_H
#define LISPNODE_H

#include <string>
#include "pos.h"

class Data;

///@brief Один элемент синтаксического дерева.
class LispNode
{
    friend class ListData;
public:
    LispNode(const Pos & pos):data(0),pos(pos){}
    LispNode(Data * data, const Pos & pos):data(data),pos(pos){}
    LispNode(Data * data):data(data){}
    LispNode(const LispNode &node);
    LispNode & operator= (const LispNode &node);
    LispNode():data(0){}
    ~LispNode();
    const Pos & getPos()const {return pos;}
    std::string toString() const;
    Data * data;
private:
    static std::string spaces(int n);
    std::string toString(int n) const;
    Pos pos;
};



#endif // LISPNODE_H
