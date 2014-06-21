#include "message.h"

std::string Message::typeStrings[3] = {"Error","Info","Warning"};

Message::Message(std::string str, int row, int col, MessageType messageType)
{
    this->messageType = messageType;
    this->str = str;
    this->row = row;
    this->col = col;
}

std::string Message::toString()
{
    return "[" + typeStrings[(int)messageType] + "] " + str + " row: " +
            std::to_string(row) + " col: " + std::to_string(col);
}
