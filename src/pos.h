#ifndef POS_H
#define POS_H

#include "string"

///@brief This class represents a posion in the code.
class Pos
{
public:
    Pos(int row, int col):row(row),col(col){}
    Pos(std::string str, int pos){findLineN(pos,str.c_str());}
    Pos(char * str, int pos){findLineN(pos,str);}
    Pos():row(-1),col(-1){}
    std::string toString() const;
    int getRow() const {return row;}
    int getCol() const {return col;}
private:
    void findLineN(int n, const char * str);
    int row;
    int col;
};

#endif // POS_H
