#include <QCoreApplication>
#include <QDebug>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "lispstring.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //std::ifstream ifs("../src/calc.lsp");
    std::ifstream ifs("../src/calc_ssslisp.lsp");
    std::stringstream ss;
    ss << ifs.rdbuf ();
    std::string text = ss.str();
    std::cout << text;
    qDebug() << text.size();
    //scanf("%s\n",&str);
    //qDebug() << cstr;
    LispString lispStr(text.c_str());
    qDebug() << lispStr.toString();
    std::vector<Message> messages = lispStr.getMessages();
    std::vector<Message>::iterator i;
    for (i = messages.begin(); i != messages.end(); i++)
        qDebug() << QString::fromStdString(i->toString());
    //printf("%s\n",lispStr.toString().toLatin1().data());
    getchar();
    return 0;
    return a.exec();
}
