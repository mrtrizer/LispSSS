#ifndef LISPEXECUTER_H
#define LISPEXECUTER_H

#include "heap.h"
#include "stack.h"

#include <iostream>

class LispString;

class LispExecuter
{
public:
    LispExecuter(LispString * lispString, std::ostream * out = 0, std::istream * in = 0);
    void run();

private:
    Heap heap;
    Stack stack;
    LispString * lispString;
    std::ostream * out;
    std::istream * in;

    void functionHandler(LispNode * list);
};

#endif // LISPEXECUTER_H
