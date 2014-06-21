#include "lispexecuter.h"
#include "stack.h"
#include "lispstring.h"

#include <assert.h>

LispExecuter::LispExecuter(LispString * lispString, std::ostream * out, std::istream * in)
{
    assert(lispString != 0);
    this->lispString = lispString;
    this->in = in;
    this->out = out;
}

void LispExecuter::run()
{

}

void LispExecuter::functionHandler(LispNode * list)
{
    if (list->data != 0)
    {

    }
}
