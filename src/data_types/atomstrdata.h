#ifndef ATOMSTRDATA_H
#define ATOMSTRDATA_H

#include "data.h"
#include <string>

///@brief Represents string
class AtomStrData:public Data
{
public:
    AtomStrData(const std::string & str)
    {
        for (unsigned int i = 0; i < str.size(); i++)
        {
            if (str[i] == '\\')
            {
                switch (str[i + 1])
                {
                case 'n':
                {
                    this->str += '\n';
                    i++;
                    break;
                }
                case '\\':
                {
                    this->str += '\\';
                    i++;
                    break;
                }
                case '"':
                {
                    this->str += '\"';
                    i++;
                    break;
                }
                }
            }
            else
                this->str += str[i];
        }
    }
    std::string toString() const {return '\"' + str + '\"';}
    DataType getDataType() const {return ATOM_STR;}
    Data * getClone() const {return new AtomStrData(*this);}
    std::string getString() const {return str;}
    bool isEqual(const Data * data) const
    {
        if (data->getDataType() == ATOM_STR)
            return ((AtomStrData *)data)->str == str;
        return false;
    }
    virtual unsigned int getSize() const {return str.size();}
private:
    std::string str;
};

#endif // ATOMSTRDATA_H
