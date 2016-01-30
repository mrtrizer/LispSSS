
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "lispstring.h"
#include "lispexecuter.h"
#include "lispnode.h"
#include "atomintdata.h"
#include "atomfloatdata.h"
#include "memory.h"
#include "funcdata.h"
#include "externfunction.h"
#include "lexicalanalyzer.h"

char * foo(unsigned int x, float y)
{
    (void)x;
    (void)y;
    printf ("THIS IS HAIFA! %d %f\n", x, y);
    return strdup("THIS IS SPARTA!");
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    const char * code = "print (foo 5 100.0);";

    LispString lispStr(code);
    if (!lispStr.isValid())
        return 1;
    LispExecuter lispExecuter(&lispStr,&std::cout,&std::cout,&std::cin);
    Memory variables(0);
    double test = 0;
    variables.setVar(Var("test",new AtomFloatData(test)));
    //Extern function adding
    std::vector<ArgumentName> argumentNames;
    argumentNames.push_back(ArgumentName("a",&ffi_type_uint));
    argumentNames.push_back(ArgumentName("b",&ffi_type_float));
    variables.setVar(Var("foo",new FuncData(new ExternFunction(argumentNames,(void(*)(void))foo,&ffi_type_pointer),&variables)));
    //Runing
    lispExecuter.run(variables);

    getchar();
    return 0;
}
