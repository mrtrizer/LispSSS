#include "lispstring.h"
#include "stdio.h"
#include "lispnode.h"

#include <QDebug>
#include <assert.h>

#define IS_SPACE(c) ((c == ' ') || (c == '\n') || (c == '\t') || (c != 0))
#define PARSE_ERROR(s,n) throw parse_error(Message(s,findStrN(n),n,Message::ERROR))

LispNode * LispString::parseAtom(char * str, int * i)
{
    LispNode * atom = new LispNode;
    atom->dataType = ATOM;
    char * data = new char[255];

    int j = 0;
    if (str[*i] == '\"')
    {
        (*i)++;
        while (str[*i] != '\"')
        {
            data[j] = str[*i];
            j++;
            (*i)++;
        }
        (*i)++;
        data[j] = 0;
        atom->dataType = ATOM_STR;
        atom->data = data;
    }
    else
    {
        while ((str[*i] != '\t') && (str[*i] != '\n') && (str[*i] != ' ') && (str[*i] != ')') && (str[*i] != 0))
        {
            (data)[j] = str[*i];
            j++;
            (*i)++;
        }
        (data)[j] = 0;
        if (((data[0] >= '0') && (data[0] <= '9')) || ((data[0] == '-') && (data[1] >= '0') && (data[1] <= '9')))
        {
            double * floatNum = new double;
            *floatNum = atof(data);
            atom->data = (void *) floatNum;
            atom->dataType = ATOM_FLOAT;
            delete []data;
        }
        else
        {
            atom->data = data;
        }
    }
    (*i)--;
    return atom;
}

LispNode * LispString::parseList(char * str, int * i, bool noFrame)
{
    LispNode * list = new LispNode;
    list->dataType = LIST;
    list->data = 0;
    list->next = 0;
    LispNode * current = 0;
    while (1)
    {
        (*i)++;
        if (*i > 1000)
            PARSE_ERROR("Prog length must be < 1000 ", *i);
        switch (str[*i])
        {
            case '(':
                if (current == 0)
                    list->data = current = parseList(str,i);
                else
                {
                    current->next = parseList(str,i);
                    current = current->next;
                }
                break;
            case '{':
                if (current == 0)
                    list->data = current = parsePacket(str,i);
                else
                {
                    current->next = parsePacket(str,i);
                    current = current->next;
                }
                break;
            case ')':
                if (!noFrame)
                    return list;
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
                    return list;
                }
                else
                    PARSE_ERROR("Bracket missed",*i);
                break;
            default:
                if (current == 0)
                    list->data = current = parseAtom(str,i);
                else
                {
                    current->next = parseAtom(str,i);
                    current = current->next;
                }
                break;
        }
    }
    return list;
}

LispNode * LispString::parsePacket(char * str, int * i, bool first)
{
    (void)str;
    (void)i;
    LispNode * packet = new LispNode();
    packet->dataType = LIST;
    packet->data = 0;
    LispNode * current = 0;
    LispNode * nameAtom = new LispNode();
    if (first)
        nameAtom->data = (void *)"__function_list";
    else
        nameAtom->data = (void *)"prog";
    nameAtom->dataType = ATOM;
    nameAtom->next = 0;
    current = nameAtom;
    packet->data = (void *)current;
    while (1)
    {
        (*i)++;
        if (*i > 1000)
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
                if (current == 0)
                {
                    current = parseList(str, i,true);
                    packet->data = current;
                }
                else
                {
                    current->next = parseList(str, i, true);
                    current = current->next;
                }
                current->next = 0;
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
            valid = true;
        }
    }
    catch (parse_error & e)
    {
        messages.push_back(e.getMessage());
        firstItem = 0;
        valid = false;
    }
}

#ifdef _QT_

void LispString::printAtom(LispNode * item, QString * str)
{
    switch (item->dataType)
    {
        case ATOM:
            str->append((char *)item->data);
            str->append('\n');
        break;
        case ATOM_STR:
            str->append('\"');
            str->append((char *)item->data);
            str->append('\"');
            str->append('\n');
        break;
        case ATOM_INT:
            str->append(QString::number(*((int *)item->data)));
            str->append('\n');
        break;
        case ATOM_FLOAT:
            str->append(QString::number(*((double *)item->data)));
            str->append('\n');
        break;
    }
}

void LispString::printList(LispNode * root, QString * str, int n)
{
    LispNode * tmp = root;
    while (tmp != 0)
    {
        for (int i = 0; i < n; i++)
            str->append((char)'-');
        str->append((char)'|');
        str->append(' ');
        if (tmp->dataType == LIST)
        {
            str->append(QString("list\n"));
            printList((LispNode *)tmp->data,str,n+1);
        }
        else
            printAtom(tmp,str);
        tmp = tmp->next;
    }
}

QString LispString::toString()
{
    QString text;
    if (!valid)
        return QString("Not valid!");
    if (firstItem->dataType == LIST)
        printList(firstItem,&text);
    else
        printAtom(firstItem,&text);
    return text;
}
#endif


