#include "pos.h"

void Pos::findLineN(int n, const char *str)
{
    row = 0;
    col = 0;
    for (int i = 0; i < n; i++)
    {
        col++;
        if (str[i] == 0)
        {
            row = -1;
            col = -1;
        }
        if (str[i] == '\n')
        {
            row++;
            col = 0;
        }
    }
}

std::string Pos::toString() const
{
    if ((row < 0) || (col < 0))
        return "[Position in not defined]";
    else
        return " [" + std::to_string(row + 1) + ":" + std::to_string(col + 1) + "]"; //I do it not so often.
}
