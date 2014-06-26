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
            if ((str[i] == '\\') && (str[i + 1] == 'n'))
            {
                this->str += '\n';
                i++;
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
private:
    std::string str;
};

#endif // ATOMSTRDATA_H
