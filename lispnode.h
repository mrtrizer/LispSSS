#ifndef LISPNODE_H
#define LISPNODE_H

#include <string>

///@brief Represents data
class Data
{
public:
    enum DataType {LIST = 1, ATOM = 2, ATOM_STR = 4, ATOM_INT = 8, ATOM_FLOAT = 16, ATOM_T = 32, ATOM_NIL = 64};

    virtual ~Data(){}
    virtual std::string toString() const = 0;
    virtual DataType getDataType() const = 0;
    virtual Data * getClone() const = 0;
    virtual bool isEqual(const Data * data) const = 0;
};

///@brief Один элемент синтаксического дерева.
class LispNode
{
public:
    LispNode();
    LispNode(const LispNode &node);
    ~LispNode();
    std::string toString();
    Data * data;
    LispNode * next;
private:
    std::string toString(LispNode * item, int n);
};

///@brief Represents list
class ListData:public Data
{
public:
    ListData(LispNode * node){this->firstNode = node;}
    ~ListData(){delete firstNode;}
    std::string toString() const {return firstNode->toString();}
    LispNode * getRoot() const {return firstNode;}
    DataType getDataType() const {return LIST;}
    Data * getClone() const {return new ListData(new LispNode(*firstNode));}
    bool isEqual(const Data * data) const {(void)data; return false;}
private:
    LispNode * firstNode;
};

///@brief Represents atom
class AtomData:public Data
{
public:
    AtomData(const std::string & str){this->str = str;}
    std::string toString() const {return str;}
    DataType getDataType() const {return ATOM;}
    Data * getClone() const {return new AtomData(*this);}
    std::string getName() const {return str;}
    bool isEqual(const Data * data) const
    {
        if (data->getDataType() == ATOM)
            return ((AtomData *)data)->str == str;
        return false;
    }
private:
    std::string str;
};

///@brief Represents string
class AtomStrData:public Data
{
public:
    AtomStrData(const std::string & str){this->str = str;}
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

///@brief Represents integer
class AtomIntData:public Data
{
public:
    AtomIntData(int num){this->num = num;}
    std::string toString() const {return std::to_string(num);}
    DataType getDataType() const {return ATOM_INT;}
    Data * getClone() const {return new AtomIntData(*this);}
    bool isEqual(const Data * data) const
    {
        if (data->getDataType() == ATOM_INT)
            return ((AtomIntData *)data)->num == num;
        return false;
    }
    int getNum() const {return num;}
private:
    int num;
};

///@brief Represents float
class AtomFloatData:public Data
{
public:
    AtomFloatData(float num){this->num = num;}
    std::string toString() const {return std::to_string(num);}
    DataType getDataType() const {return ATOM_FLOAT;}
    Data * getClone() const {return new AtomFloatData(*this);}
    bool isEqual(const Data * data) const
    {
        if (data->getDataType() == ATOM_FLOAT)
            return ((AtomFloatData *)data)->num == num;
        return false;
    }
    float getNum() const {return num;}
private:
    float num;
};

///@brief Represents true atom
class AtomTData:public Data
{
public:
    std::string toString() const {return std::string("T");}
    DataType getDataType() const {return ATOM_T;}
    Data * getClone() const {return new AtomTData(*this);}
    bool isEqual(const Data * data) const
    {
        if (data->getDataType() == ATOM_T)
            return true;
        return false;
    }
};

///@brief Represents nil atom
class AtomNilData:public Data
{
public:
    std::string toString() const {return std::string("nil");}
    DataType getDataType() const {return ATOM_NIL;}
    Data * getClone() const {return new AtomNilData(*this);}
    bool isEqual(const Data * data) const
    {
        if (data->getDataType() == ATOM_NIL)
            return true;
        return false;
    }
};


#endif // LISPNODE_H
