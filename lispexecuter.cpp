#include "lispexecuter.h"
#include "stack.h"
#include "lispstring.h"
#include "funccontroller.h"
#include "lispnode.h"
#include "function.h"
#include "stack.h"

#include <assert.h>

LispExecuter::LispExecuter(LispString * lispString, std::ostream * errout,
                           std::ostream * out, std::istream * in):funcController(this,&stack,out,in)
{
    assert(lispString != 0);
    this->lispString = lispString;
    this->in = in;
    this->out = out;
    this->errout = errout;
}

void LispExecuter::run()
{
    if (!lispString->isValid())
        return;
    try
    {
        stack.blockPush();
        *errout << functionHandler(lispString->getRoot()->data).getData()->toString();
        stack.blockPop();
    }
    catch (Message & m)
    {
        *errout << m.toString();
    }
}

Result LispExecuter::functionHandler(const Data * data)
{
    if (data->getDataType() == Data::LIST)
    {
        ListData * listData = (ListData *)data;
        if (listData->getRoot()->data->getDataType() == Data::ATOM)
        {
            AtomData * firstItem = (AtomData *)listData->getRoot()->data;
            Function * func = funcController.getFunction(firstItem->getName());
            switch (func->type)
            {
                case Function::EXPR:
                case Function::SUBR:
                {
                    Arguments arguments;
                    LispNode * tmp = listData->getRoot()->next;
                    while (tmp != 0)
                    {
                        arguments.push_back((Value)functionHandler(tmp->data));
                        tmp = tmp->next;
                    }
                    return func->run(arguments);
                    break;
                }
                case Function::MACRO:
                case Function::FEXPR:
                case Function::FSUBR:
                {
                    return func->run(Arguments::fromLispNode(listData->getRoot()->next));
                    break;
                }
            }
        }
    }
    if (data->getDataType() == Data::ATOM)
        return (Result)stack.findVar(((AtomData *)data)->getName()).value;
    return Result(data->getClone());
}
