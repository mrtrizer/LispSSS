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
    if (!lispString->isValid())
        return;
    try
    {
        *errout << functionHandler(lispString->getRoot()).getData()->toString();
    }
    catch (Message & m)
    {
        *errout << m.toString();
    }
}

Result LispExecuter::functionHandler(LispNode * list)
{
    if (list->data->getDataType() == Data::LIST)
    {
        ListData * listData = (ListData *)list->data;
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
                        arguments.push_back((Value)functionHandler(tmp));
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
    return Result(list->data->getClone());
}
