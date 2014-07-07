
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
    printf ("THIS IS HAIFA!\n");
    return strdup("THIS IS SPARTA!");
}

int main(int argc, char *argv[])
{
    //std::ifstream ifs("../src/calc.lsp");
    //std::ifstream ifs("../src/calc_ssslisp.lsp");
    //std::ifstream ifs("../src/sort.sss");
    //std::ifstream ifs("../src/func_test.sss");
    //std::ifstream ifs("../src/test.sss");
    //std::ifstream ifs("../src/test_simple.sss");
    //std::ifstream ifs("../src/operator_tests.sss");
    std::ifstream ifs;
    if (argc < 2)
    {
        std::cout << "Use this format: \n playLisp <file>\n";
        return 0;
    }
    else
        ifs.open(argv[1]);
    LexicalAnalyzer la(&ifs);
    Lexem l;
    try
    {
        while (l.getType() != Lexem::ZERO)
        {
            l = la.getNextLexem();
            std::cout << l.toString() << std::endl;
        }
    }
    catch(Message & m)
    {
        std::cout << m.toString();
    }

//    std::stringstream ss;
//    ss << ifs.rdbuf ();
//    std::string text = ss.str();
//    //std::cout << text;
//    {
//        LispString lispStr(text.c_str());
//        if (!lispStr.isValid())
//        {
//            std::cout << "Parse error!" << std::endl;
//            std::vector<Message> messages = lispStr.getMessages();
//            std::vector<Message>::iterator i;
//            for (i = messages.begin(); i != messages.end(); i++)
//                std::cout << i->toString();
//            return 1;
//        }
//        LispExecuter lispExecuter(&lispStr,&std::cout,&std::cout,&std::cin);
//        Memory variables(0);
//        double test = 0;
//        variables.setVar(Var("test",new AtomFloatData(test)));
//        //Extern function adding
//        std::vector<ArgumentName> argumentNames;
//        argumentNames.push_back(ArgumentName("a",&ffi_type_uint));
//        argumentNames.push_back(ArgumentName("b",&ffi_type_float));
//        variables.setVar(Var("foo",new FuncData(new ExternFunction(argumentNames,&lispExecuter,(void(*)(void))foo,&ffi_type_pointer),&variables)));
//        //Runing
//        lispExecuter.run(&variables);
//    }
    getchar();
    return 0;
}
