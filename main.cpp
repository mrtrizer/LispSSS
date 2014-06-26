
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
    std::stringstream ss;
    ss << ifs.rdbuf ();
    std::string text = ss.str();
    //std::cout << text;
    {
        LispString lispStr(text.c_str());
        if (!lispStr.isValid())
        {
            std::cout << "Parse error!" << std::endl;
            std::vector<Message> messages = lispStr.getMessages();
            std::vector<Message>::iterator i;
            for (i = messages.begin(); i != messages.end(); i++)
                std::cout << i->toString();
            return 1;
        }
        LispExecuter lispExecuter(&lispStr,&std::cout,&std::cout,&std::cin);
        Memory variables(0);
        double test = 0;
        variables.setVar(Var("test",new AtomFloatData(test)));
        lispExecuter.run(&variables);
        test = ((AtomFloatData*)variables.findVar("test").value.getData())->getNum();
        std::cout << std::endl << test << std::endl;
    }
    getchar();
    return 0;
}
