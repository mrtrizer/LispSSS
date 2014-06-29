#include "message.h"

std::string Message::typeStrings[3] = {"Error","Info","Warning"};

Message::Message(std::string str, Pos pos, MessageType messageType)
{
    this->messageType = messageType;
    this->str = str;
    this->pos = pos;
}

Message::Message(std::string str, MessageType messageType)
{
    this->messageType = messageType;
    this->str = str;
}

std::string Message::toString()
{
    return "[" + typeStrings[(int)messageType] + "] " + str + pos.toString();
}
