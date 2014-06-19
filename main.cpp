#include <QCoreApplication>
#include <QDebug>
#include <cstdio>
#include "lispstring.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char str[1024] = "(if (= (readL \"num:\") 2))";
    //scanf("%s\n",&str);
    //qDebug() << cstr;
    LispString lispStr((char *)&str);
    //qDebug() << lispStr.toString();
    printf("%s\n",lispStr.toString().toLatin1().data());
    //getchar();
    return 0;
    return a.exec();
}
