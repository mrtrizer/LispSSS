#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "pos.h"

class Message
{
public:
    enum MessageType {ERROR = 0, INFO = 1, WARNING = 2};
    Message(std::string str, Pos pos, MessageType messageType);
    ///@brief Use this constructor if a instruction pos is unknown.
    Message(std::string str, MessageType messageType);
    std::string toString();
    ///@brief Use this method if you knew a position.
    void setPos(const Pos & pos){this->pos = pos;}
private:
    static std::string typeStrings[3];
    MessageType messageType;
    std::string str;
    Pos pos;
};

#define ERROR_MESSAGE(str) throw Message(str,Message::ERROR);

#endif // MESSAGE_H
