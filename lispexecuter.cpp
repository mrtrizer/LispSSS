#include "lispexecuter.h"
#include "stack.h"
#include "lispstring.h"
#include "funccontroller.h"
#include "lispnode.h"
#include "function.h"

#include <assert.h>

LispExecuter::LispExecuter(LispString * lispString, std::ostream * errout,
                           std::ostream * out, std::istream * in):funcController(this,out,in)
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
        *errout << functionHandler(lispString->getRoot()->data).getData()->toString();
    }
    catch (Message & m)
    {
        *errout << m.toString();
    }
}

Result LispExecuter::functionHandler(Data * data)
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
    return Result(data->getClone());
}
