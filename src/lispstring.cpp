#include "lispstring.h"
#include "stdio.h"
#include "lispnode.h"
#include "data.h"
#include "atomstrdata.h"
#include "atomfloatdata.h"
#include "atomintdata.h"
#include "atomtdata.h"
#include "atomnildata.h"
#include "atomdata.h"
#include "listdata.h"

#include <QDebug>
#include <assert.h>

#define IS_SPACE(c) ((c == ' ') || (c == '\n') || (c == '\t') || (c != 0))
#define PARSE_ERROR(s,pos) throw parse_error(Message(s,pos,Message::ERROR))

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
    LispNode * atom = new LispNode(Pos(str,*i));

    int iStart = *i;
    if (str[*i] == '\"')
    {
        (*i)++;
        while (1)
        {
            if (str[*i] == '\\')
                (*i)++;
            else
                if (str[*i] == '\"')
                    break;
            (*i)++;
        }
        (*i)++;
        atom->data = new AtomStrData(std::string(str + iStart + 1,*i - iStart - 2));
    }
    else
    {
        //While not lexem end
        while ((str[*i] != '\t') && (str[*i] != '\n') && (str[*i] != ';') &&
               (str[*i] != ' ') && (str[*i] != ')') && (str[*i] != '(') && (str[*i] != 0))
            (*i)++;

        //Is number
        if (((str[iStart] >= '0') && (str[iStart] <= '9')) ||
                ((str[iStart] == '-') && (str[iStart + 1] >= '0') && (str[iStart + 1] <= '9')))
        {
            std::string numStr(str + iStart,*i - iStart);
            int pointCount = 0;
            for (unsigned int i = 0; i < numStr.size(); i++)
                if ((numStr[i] == '.') or (numStr[i] == ','))
                    pointCount++;
            if (pointCount > 1)
            {
                delete atom;
                PARSE_ERROR("Wrong number!",Pos(str,*i));
            }
            if (pointCount == 1)
                atom->data = new AtomFloatData(atof(numStr.c_str()));
            else
                atom->data = new AtomIntData(atoi(numStr.c_str()));
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
    LispNode * list = new LispNode(Pos(str,*i));
    ListData * listData;
    list->data = listData = new ListData();
    while (1)
    {
        (*i)++;
//        if (*i > 1000) //FOR DEBUG
//            PARSE_ERROR("Prog length must be < 1000 ", *i);
        switch (str[*i])
        {
            case '(':
                listData->list.push_back(*parseList(str,i));
                break;
            case '{':
                listData->list.push_back(*parsePacket(str,i));
                break;
            case ')':
                if (!noFrame)
                    return list;
                else
                    PARSE_ERROR("Bad string end must be \':\' or \';\' ",Pos(str,*i));
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
                    return list;
                }
                else
                    PARSE_ERROR("Bracket missed",Pos(str,*i));
                break;
            default:
                listData->list.push_back(*parseAtom(str,i));
                break;
        }
    }
}

LispNode * LispString::parsePacket(char * str, int * i, bool first)
{
    LispNode * packet = new LispNode(Pos(str,*i));
    ListData * listData;
    packet->data = listData = new ListData();
    listData->list.push_back(LispNode(new AtomData("prog"),Pos(str,*i)));

    while (1)
    {
        (*i)++;
//        if (*i > 1000) //FOR DEBUG
//            PARSE_ERROR("Prog length must be < 1000", *i);
        switch (str[*i])
        {
            case ';': break;
            case ':': break;
            case '}': return packet; break;
            case ' ': break;
            case '#':
                while ((str[*i] != '\n') && str[*i] != 0)
                    (*i)++;
                break;
            case '\n': break;
            case '\t': break;
            case 0:
                if (first)
                    return packet;
                else
                    PARSE_ERROR("Bracket missed P",Pos(str,*i));
                break;
            default:
                (*i)--;
                listData->list.push_back(*parseList(str, i, true));
                break;
        }
    }
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

