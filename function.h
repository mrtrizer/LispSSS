#ifndef FUNCTION_H
#define FUNCTION_H

#include "lispnode.h"
#include "value.h"
#include "message.h"

#include <vector>

#define ERROR_MESSAGE(str) throw Message(str,0,0,Message::ERROR);

class Arguments:public std::vector<Value>
{
public:
    static Arguments fromLispNode(LispNode * node);
};

typedef Value Result;

class Function
{
public:
    ///@brief Lisp function types
    enum FunctionType {
        SUBR = 0, //Встроенные. Вычисляющие значения агрументов.
        FSUBR = 1, //Встроенные. Не вычисляющие значения аргументов.
        EXPR = 2, //Lisp. Вычисляющие значения аргументов.
        FEXPR = 3, //Lisp. Не вычисляющие значения агрументов.
        MACRO = 4 //Lisp. Не вычисляющие значения агрументов. Максросы.
    };

    Function(const std::string & name, FunctionType type, int argCount = -1, int minArgCount = 0);
    virtual ~Function(){}
    Result run(const Arguments &arguments);
    ///@brief Argument count. Set -1 when argCount not fixed.
    int argCount;
    ///@brief Min argument count. Used when argCount = -1. Can be 0.
    int minArgCount;
    ///@brief Function name
    std::string name;
    ///@brief Function type
    FunctionType type;
private:
    virtual Result run_(const Arguments & arguments) = 0;
};

#endif // FUNCTION_H
