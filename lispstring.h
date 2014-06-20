#ifndef LISPSTRING_H
#define LISPSTRING_H

#include "config.h"

#ifdef _QT_
#include <QObject>
#endif

//Function types
#define SUBR 0 //Встроенные. Вычисляющие значения агрументов.
#define FSUBR 1 //Встроенные. Не вычисляющие значения аргументов.
#define EXPR 2 //Lisp. Вычисляющие значения аргументов.
#define FEXPR 3 //Lisp. Не вычисляющие значения агрументов.
#define MACRO 4 //Lisp. Не вычисляющие значения агрументов. Максросы.

//Lexem type
#define LIST 0
#define ATOM 1
#define ATOM_STR 2
#define ATOM_INT 3
#define ATOM_FLOAT 4
#define ATOM_T 5
#define ATOM_NIL 6

///@brief Класс лисп строки. В конструкторе парсит строку и предоставляет доступ к синтаксическому дереву строки.
class LispString
{
public:
    ///@brief exception class
    class parse_error
    {
    public:
        parse_error(QString str){this->str = str;}
        QString str;
    };

    ///@brief Один элемент синтаксического дерева.
    typedef class Item
    {
    public:
        Item():data(0),dataType(0),next(0){}
        void * data;
        unsigned char dataType;
        Item * next;
    } Item;
    ///@brief Конструктор
    LispString(char *str){setLispString(str);}
    ///@brief Возвращает результат парсинга строки.
    bool isValid(){return valid;}
#ifdef _QT_
    ///@brief Конструктор, переопределенный для Qt
    LispString(const QString & str){setLispString(str.toLocal8Bit().data());}
    ///@brief Приведение к строке для Qt.
    QString toString();
#endif

private:
    ///@brief Определяет правильность строки. Определяется на этапе разбора.
    bool valid;
    char * str;
    ///@brief Первый элемент. Определяет корень синтаксического дерева.
    Item * firstItem;
    ///@brief Анализирует атом. Определяет тип и содержание.
    Item * parseAtom(char * str, int * i);
    ///@brief Парсит список (рекурсивная)
    Item * parseList(char * str, int * i, bool noFrame = false);
    ///@brief Parse packet
    Item * parsePacket(char * str, int * i, bool first = false);
    ///@brief Search str number. It is need for debug.
    int findStrN(int n);
    ///@brief Starts parsing
    void setLispString(char *str);

    //Только для Qt (_QT_ искать в config.h)
#ifdef _QT_
    ///@brief Добавляет к str атом
    void printAtom(Item * item, QString *str);
    ///@brief Добавляет к str список (рекурсивная)
    void printList(Item * root, QString *str, int n = 0);
#endif
};

#endif // LISPSTRING_H
