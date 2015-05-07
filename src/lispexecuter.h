#ifndef LISPEXECUTER_H
#define LISPEXECUTER_H

#include "heap.h"
#include "pos.h"

#include <iostream>

class LispString;
class Value;
class Memory;
class Data;

typedef Value Result;

class LispExecuter
{
public:
    LispExecuter(LispString * lispString, std::ostream *errout = &std::cout, std::ostream * out = 0, std::istream * in = 0);
    void run(Memory &global);
    Result functionHandler(const Data *data, Memory *stack);

private:
    Heap heap;
    LispString * lispString;
    std::ostream * errout;
    std::ostream * out;
    std::istream * in;
    Pos curPos;
};

#endif // LISPEXECUTER_H
