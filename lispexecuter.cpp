#include "lispexecuter.h"
#include "stack.h"
#include "lispstring.h"
#include "funccontroller.h"
#include "lispnode.h"
#include "function.h"

#include <assert.h>

LispExecuter::LispExecuter(LispString * lispString, std::ostream * errout,std::ostream * out, std::istream * in)
{
    assert(lispString != 0);
    this->lispString = lispString;
    this->in = in;
    this->out = out;
    this->errout = errout;
}

void LispExecuter::run()
{
    try
    {
        *errout << functionHandler(lispString->getRoot()).node->toString();
    }
    catch (Message & m)
    {
        *errout << m.toString();
    }
}

Result LispExecuter::functionHandler(LispNode * list)
{
    return Result(new LispNode());
}
