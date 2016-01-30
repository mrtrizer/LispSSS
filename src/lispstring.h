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

    LispString(const std::string & str);
    ~LispString();
    bool isValid() const {return valid;}
    const std::vector<Message> & getMessages() const {return messages;}
    LispNode * getRoot(){return firstItem;}

#ifdef _QT_
    QString getErrorMessages();
    LispString(const QString & str){setLispString(str.toLocal8Bit().data());}
    QString toString();
#endif

private:
    bool valid;
    std::vector<Message> messages;
    std::string str;
    LispNode * firstItem;
    LispNode * parseAtom(const char * str, int * i);
    LispNode * parseList(const char * str, int * i, bool noFrame = false);
    LispNode * parsePacket(const char * str, int * i, bool first = false);
    void findLineN(int n, char *str, int &line, int &pos);
    void setLispString(const std::string &str);
};

#endif // LISPSTRING_H
