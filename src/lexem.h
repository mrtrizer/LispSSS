#ifndef LEXEM_H
#define LEXEM_H

#include <string>

class Data;

class Lexem
{
public:
    enum LexemType {OPEN_BRACKET = 0,
                    CLOSE_BRACKET = 1,
                    OPEN_PACKET = 2,
                    CLOSE_PACKET = 3,
                    QOUTE = 4,
                    DATA = 5,
                    ZERO = 6,
                    COMMENT = 7,
                    SEMICOLON = 8,
                    NOT_DEFINED = 9};
    Lexem(LexemType type, Data * data = 0);
    Lexem();
    ~Lexem();
    Lexem(const Lexem & lexem);
    Lexem & operator=(const Lexem & lexem);
    std::string toString() const;
    LexemType getType(){return type;}
private:
    Data * data;
    LexemType type;
};

#endif // LEXEM_H
