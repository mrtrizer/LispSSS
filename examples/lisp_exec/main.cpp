
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

int main(int argc, char *argv[])
{
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
        lispExecuter.run(variables);
    }
    return 0;
}
