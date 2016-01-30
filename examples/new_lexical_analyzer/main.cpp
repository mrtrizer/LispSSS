
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

    getchar();
    return 0;
}
