#include "lispstring.h"
#include "stdio.h"

#include <QDebug>

LispString::Item * LispString::parseAtom(char * str, int * i)
{
    Item * atom = new Item;
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
        if ((data[0] >= '0') && (data[0] <= '9') || ((data[0] == '-') && (data[1] >= '0') && (data[1] <= '9')))
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

LispString::Item * LispString::parseList(char * str, int * i)
{
    Item * list = new Item;
    list->dataType = LIST;
    list->data = 0;
    list->next = 0;
    Item * current = 0;
    while (1)
    {
        (*i)++;
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
            case ')': return list; break;
            case ' ': break;
            case '\n': break;
            case '\'': break;
            case '\t': break;
            default:
                if (current == 0)
                    list->data = current = parseAtom(str,i);
                else
                {
                    current->next = parseAtom(str,i);
                    current = current->next;
                }
        }

    }
    return list;
}

void LispString::setLispString(char * str)
{
    int i = 0;
    if (str[0] == '(')
        firstItem = parseList(str, &i);
    else
        firstItem = parseAtom(str, &i);
}

#ifdef _QT_

void LispString::printAtom(Item * item, QString * str)
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

void LispString::printList(Item * root, QString * str, int n)
{
    Item * tmp = root;
    while (tmp != 0)
    {
        for (int i = 0; i < n; i++)
            str->append((char)'-');
        str->append((char)'|');
        str->append(' ');
        if (tmp->dataType == LIST)
        {
            str->append(QString("list\n"));
            printList((Item *)tmp->data,str,n+1);
        }
        else
            printAtom(tmp,str);
        tmp = tmp->next;
    }
}

QString LispString::toString()
{
    QString text;
    if (firstItem->dataType == LIST)
        printList(firstItem,&text);
    else
        printAtom(firstItem,&text);
    return text;
}
#endif


