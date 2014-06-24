#ifndef FUNCTION_H
#define FUNCTION_H

#include "lispnode.h"
#include "value.h"
#include "message.h"
#include "memory.h"

#include <vector>
#include <string>

class Arguments:public std::vector<Value>
{
public:
    static Arguments fromLispNode(LispNode * node);
};

typedef Value Result;

class Memory;

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

    Function(FunctionType type, int argCount = -1, int minArgCount = 0);
    virtual ~Function(){}
    Result run(const Arguments &arguments, Memory *stack) const;
    ///@brief Returns string representing of function
    std::string toString() const {return "FUNC";}
    ///@brief Returns function name
    virtual std::string getName() const {return "NO NAME";}
    ///@brief Argument count. Set -1 when argCount not fixed.
    int argCount;
    ///@brief Min argument count. Used when argCount = -1. Can be 0.
    int minArgCount;
    ///@brief Function type
    FunctionType type;
private:
    virtual Result run_(const Arguments & arguments, Memory *stack) const = 0;
};

#endif // FUNCTION_H
