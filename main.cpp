#include <QCoreApplication>
#include <QDebug>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "lispstring.h"
#include "lispexecuter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //std::ifstream ifs("../src/calc.lsp");
    //std::ifstream ifs("../src/calc_ssslisp.lsp");
    std::ifstream ifs("../src/test.sss");
    std::stringstream ss;
    ss << ifs.rdbuf ();
    std::string text = ss.str();
    std::cout << text;
    qDebug() << text.size();
    {
        LispString lispStr(text.c_str());
        LispNode test(*lispStr.getRoot());
        qDebug() << QString::fromStdString(test.toString());
        qDebug() << lispStr.toString();
        LispExecuter lispExecuter(&lispStr,&std::cout,&std::cout,&std::cin);
        lispExecuter.run();
        std::vector<Message> messages = lispStr.getMessages();
        std::vector<Message>::iterator i;
        for (i = messages.begin(); i != messages.end(); i++)
            qDebug() << QString::fromStdString(i->toString());
    }
    getchar();
    return 0;
    return a.exec();
}
