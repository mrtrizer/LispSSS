#include "lispstring.h"
#include "stdio.h"
#include "lispnode.h"

#include <QDebug>
#include <assert.h>

#define IS_SPACE(c) ((c == ' ') || (c == '\n') || (c == '\t') || (c != 0))
#define PARSE_ERROR(s,n) throw parse_error(Message(s,findStrN(n),n,Message::ERROR))

LispString::LispString(char *str):firstItem(0)
{
    setLispString(str);
}

LispString::~LispString()
{
    if (firstItem)
        delete firstItem;
}

LispNode * LispString::parseAtom(char * str, int * i)
{
    LispNode * atom = new LispNode;

    int iStart = *i;
    if (str[*i] == '\"')
    {
        (*i)++;
        while (str[*i] != '\"')
            (*i)++;
        (*i)++;
        atom->data = new AtomStrData(std::string(str + iStart + 1,*i - iStart - 2));
    }
    else
    {
        //While not lexem end
        while ((str[*i] != '\t') && (str[*i] != '\n') &&
               (str[*i] != ' ') && (str[*i] != ')') && (str[*i] != 0))
            (*i)++;

        //Is number
        if (((str[iStart] >= '0') && (str[iStart] <= '9')) ||
                ((str[iStart] == '-') && (str[iStart] >= '0') && (str[iStart] <= '9')))
        {
            std::string numStr(str + iStart,*i - iStart);
            atom->data = new AtomFloatData(atof(numStr.c_str()));
        }
        else
        {
            std::string name (str + iStart,*i - iStart);
            if (name == "T")
                atom->data = new AtomTData();
            else
            {
                if (name == "nil")
                    atom->data = new AtomNilData();
                else
                    atom->data = new AtomData(name);
            }
        }
    }
    (*i)--;
    return atom;
}

LispNode * LispString::parseList(char * str, int * i, bool noFrame)
{
    LispNode * list = new LispNode;
    LispNode * current = 0;
    LispNode * firstNode = 0;
    while (1)
    {
        (*i)++;
        if (*i > 1000) //FOR DEBUG
            PARSE_ERROR("Prog length must be < 1000 ", *i);
        switch (str[*i])
        {
            case '(':
                if (current == 0)
                    firstNode = current = parseList(str,i);
                else
                {
                    current->next = parseList(str,i);
                    current = current->next;
                }
                break;
            case '{':
                if (current == 0)
                    firstNode = current = parsePacket(str,i);
                else
                {
                    current->next = parsePacket(str,i);
                    current = current->next;
                }
                break;
            case ')':
                if (!noFrame)
                    goto EXIT;
                else
                    PARSE_ERROR("Bad string end must be \':\' or \';\' ",*i);
                break;
            case ' ': break;
            case '\n': break;
            case '\'': break;
            case '\t': break;
            case 0:
            case ';':
            case ':':
            case '}':
                if (noFrame) // If we came here from parsePacket
                {
                    (*i)--;
                    goto EXIT;
                }
                else
                    PARSE_ERROR("Bracket missed",*i);
                break;
            default:
                if (current == 0)
                    firstNode = current = parseAtom(str,i);
                else
                {
                    current->next = parseAtom(str,i);
                    current = current->next;
                }
                break;
        }
    }
    EXIT: //I used goto because we need create list before return.
    list->data = new ListData(firstNode);
    return list;
}

LispNode * LispString::parsePacket(char * str, int * i, bool first)
{
    LispNode * packet = new LispNode();
    LispNode * current = new LispNode();
    if (first)
        current->data = new AtomData(std::string("__global"));
    else
        current->data = new AtomData(std::string("prog"));
    packet->data = new ListData(current);
    while (1)
    {
        (*i)++;
        if (*i > 1000) //FOR DEBUG
            PARSE_ERROR("Prog length must be < 1000", *i);
        switch (str[*i])
        {
            case ';': break;
            case ':': break;
            case '}': return packet; break;
            case ' ': break;
            case '\n': break;
            case '\t': break;
            case 0:
                if (first)
                    return packet;
                else
                    PARSE_ERROR("Bracket missed P",*i);
                break;
            default:
                (*i)--;
                    current->next = parseList(str, i, true);
                    current = current->next;
                break;
        }
    }
}

int LispString::findStrN(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (str[i] == '\n')
            count++;
    return count;
}

void LispString::setLispString(char * str)
{
    try
    {
        this->str = str;
        int i = 0;
        if (str[0] == '(')
            firstItem = parseList(str, &i);
        else
        {
            if (str[0] != '{')
                i--;
            firstItem = parsePacket(str, &i,true);
        }
        valid = true;
    }
    catch (parse_error & e)
    {
        messages.push_back(e.getMessage());
        firstItem = 0;
        valid = false;
    }
}

#ifdef _QT_

QString LispString::toString()
{
    if (!valid)
        return "Not valid script! See messages.";
    return QString::fromStdString(firstItem->toString());
}
#endif

