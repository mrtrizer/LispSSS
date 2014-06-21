#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message
{
public:
    enum MessageType {ERROR = 0, INFO = 1, WARNING = 2};
    Message(std::string str, int row, int col, MessageType messageType);
    std::string toString();
private:
    static std::string typeStrings[3];
    MessageType messageType;
    std::string str;
    int row;
    int col;
};

#endif // MESSAGE_H
