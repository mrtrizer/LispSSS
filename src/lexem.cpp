#include "lexem.h"
#include "data.h"

const char* lexemNames[] = {"OPEN_BRACKET",
                            "CLOSE_BRACKET",
                            "OPEN_PACKET",
                            "CLOSE_PACKET",
                            "QOUTE",
                            "DATA",
                            "ZERO",
                            "COMMENT",
                            "SEMICOLON",
                            "NOT_DEFINED"};

Lexem::Lexem(LexemType type, Data * data):data(data),type(type)
{
}

Lexem::Lexem():data(0),type(NOT_DEFINED)
{

}

Lexem::~Lexem()
{
    if (data != 0)
        delete data;
}

Lexem::Lexem(const Lexem &lexem)
{
    type = lexem.type;
    data = lexem.data->getClone();
}

std::string Lexem::toString() const
{
    std::string str;
    str += std::string(lexemNames[(unsigned int) type]);
    if (data)
        str += ": " + data->toString();
    return str;
}

Lexem & Lexem::operator=(const Lexem & lexem)
{
    if (data)
        delete data;
    if (lexem.data == 0)
        data = 0;
    else
        data = lexem.data->getClone();
    type = lexem.type;
    return *this;
}
