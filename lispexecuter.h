#ifndef LISPEXECUTER_H
#define LISPEXECUTER_H

#include "heap.h"
#include "stack.h"

#include <iostream>

class LispExecuter
{
public:
    LispExecuter();
private:
    Heap heap;
    Stack stack;
    std::ostream * out;
    std::istream * in;
};

#endif // LISPEXECUTER_H
