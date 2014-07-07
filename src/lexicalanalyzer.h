#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <iostream>
#include "lexem.h"

class LexicalAnalyzer
{
public:
    LexicalAnalyzer(std::istream * input);
    ~LexicalAnalyzer();
    Lexem getNextLexem();
private:
    enum State {STRING, SHIELD, INT, FLOAT, IDENTIFER, FIRST, COMMENT};
    State state;
    std::istream * input;
    int i;
    char * buff;
};

#endif // LEXICALANALYZER_H
