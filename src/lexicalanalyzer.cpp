#include "lexicalanalyzer.h"
#include "atomdata.h"
#include "atomfloatdata.h"
#include "atomintdata.h"
#include "atomnildata.h"
#include "atomtdata.h"
#include "atomstrdata.h"
#include "message.h"
#include "lexem.h"

#include <string>

#define IS_A_NUMBER(a)((a >= '0') && (a <= '9'))
#define BUFF_SIZE 100
#define IS_STR_FINISH_SYMBOL(a) ((a == '\n') || (a == 0))
#define IS_COMMENT_FINISH_SYMBOL(a) (IS_STR_FINISH_SYMBOL(a))
#define IS_ID_FINISH_SYMBOL(a) (\
((a == '(') || (a == ')') || (a == '\n') || (a == '\t') ||\
(a == ' ') || (a == ';') || (a == '\'') || (a == '"'))\
)
#define IS_SPACE_SYMBOL(a) ((a == '\n') || (a == ' ') || (a == '\t'))

LexicalAnalyzer::LexicalAnalyzer(std::istream * input):input(input),i(0)
{
    buff = new char[BUFF_SIZE];
}

LexicalAnalyzer::~LexicalAnalyzer()
{
    delete []buff;
}

Lexem LexicalAnalyzer::getNextLexem()
{
    char c;
    i = 0;
    state = FIRST;
    while (IS_SPACE_SYMBOL(input->peek()))
        input->get();
    while (true) //FIX
    {
        c = input->peek();
        switch (state)
        {
        case FIRST:
        {
            int type = -1;
            if (c == std::char_traits<char>::eof())
                type = Lexem::ZERO;
            if (c == '(')
                type = Lexem::OPEN_BRACKET;
            if (c == ')')
                type = Lexem::CLOSE_BRACKET;
            if (c == '{')
                type = Lexem::OPEN_PACKET;
            if (c == '}')
                type = Lexem::CLOSE_PACKET;
            if (c == '\'')
                type = Lexem::QOUTE;
            if (c == ';')
                type = Lexem::SEMICOLON;
            if (type != -1)
            {
                input->get();
                return Lexem((Lexem::LexemType)type);
            }
            state = IDENTIFER;
            if (IS_A_NUMBER(c) || (c == '-'))
            {
                state = INT;
                break;
            }
            if (c == '"')
            {
                state = STRING;
                break;
            }
            if (c == '#')
            {
                state = COMMENT;
                break;
            }
            break;
        }
        case STRING:
            if (c == '\\')
            {
                state = SHIELD;
                break;
            }
            if (c == '"')
            {
                input->get();
                buff[i] = 0;
                return Lexem(Lexem::DATA, new AtomStrData(strdup(buff + 1)));//Without the quote
            }
            if (IS_STR_FINISH_SYMBOL(c))
                ERROR_MESSAGE("Bad string. No an end bracket or a shash at the end of the line.");
            break;
        case SHIELD: //Current symbol will be written after the switch block.
            break;
        case INT:
            if (c == '.')
            {
                state = FLOAT;
                break;
            }
            if (!IS_A_NUMBER(c))
                return Lexem(Lexem::DATA, new AtomIntData(atoi(buff)));
            break;
        case FLOAT:
            if (c == '.')
                ERROR_MESSAGE("Bad number. Extra points.");
            if (!IS_A_NUMBER(c))
                return Lexem(Lexem::DATA, new AtomFloatData(atof(buff)));
            break;
        case IDENTIFER:
            if (IS_ID_FINISH_SYMBOL(c))
            {
                buff[i] = 0;
                return Lexem(Lexem::DATA, new AtomData(strdup(buff)));
            }
            break;
        case COMMENT:
            if (IS_COMMENT_FINISH_SYMBOL(c))
                return Lexem(Lexem::COMMENT);
        }
        c = input->get();
        buff[i] = c;
        i++;
        if (i >= BUFF_SIZE)
            ERROR_MESSAGE("So long Lexem. Lexem must be shorter than " + std::to_string(BUFF_SIZE) + " symbols.");
    }
    ERROR_MESSAGE("Parse error.");
}
