#ifndef LISPSTRING_H
#define LISPSTRING_H

#include "config.h"

#ifdef _QT_
#include <QObject>
#endif

#include "message.h"

#include <vector>

class LispNode;

///@brief Класс лисп строки. В конструкторе парсит строку и предоставляет доступ к синтаксическому дереву строки.
class LispString
{
public:
    ///@brief Exception class
    class parse_error
    {
    public:
        parse_error(const Message & message):message(message){}
        Message & getMessage(){return message;}
    private:
        Message message;
    };

    ///@brief Конструктор
    LispString(char *str);
    ///@brief Destructor
    ~LispString();
    ///@brief Возвращает результат парсинга строки.
    bool isValid(){return valid;}
    ///@brief Returns messages
    const std::vector<Message> & getMessages(){return messages;}
    ///@brief Returns firstItem
    LispNode * getRoot(){return firstItem;}

#ifdef _QT_
    ///@brief Method returns
    QString getErrorMessages();
    ///@brief Конструктор, переопределенный для Qt
    LispString(const QString & str){setLispString(str.toLocal8Bit().data());}
    ///@brief Приведение к строке для Qt.
    QString toString();
#endif

private:
    ///@brief Определяет правильность строки. Определяется на этапе разбора.
    bool valid;
    std::vector<Message> messages;
    ///@brief String for parsing
    char * str;
    ///@brief Первый элемент. Определяет корень синтаксического дерева.
    LispNode * firstItem;
    ///@brief Анализирует атом. Определяет тип и содержание.
    LispNode * parseAtom(char * str, int * i);
    ///@brief Парсит список (рекурсивная)
    LispNode * parseList(char * str, int * i, bool noFrame = false);
    ///@brief Parse packet
    LispNode * parsePacket(char * str, int * i, bool first = false);
    ///@brief Search str number. It is need for debug.
    int findStrN(int n);
    ///@brief Starts parsing
    void setLispString(char *str);
};

#endif // LISPSTRING_H
