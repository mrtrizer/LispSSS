
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

using namespace std;

int main(int argc, char *argv[])
{
    Memory variables(0);
    while (1)
    {
        char str[100];
        cin.getline(str,sizeof(str) / sizeof(char));
        if (str[0] == 0)
            continue;
        LispString lispStr(str);
        if (!lispStr.isValid())
        {
            cout << "Parse error!" << endl;
            vector<Message> messages = lispStr.getMessages();
            vector<Message>::iterator i;
            for (i = messages.begin(); i != messages.end(); i++)
                cout << i->toString();
        }
        LispExecuter lispExecuter(&lispStr,&cout,&cout,&cin);

        lispExecuter.run(variables);
    }

    getchar();
    return 0;
}
