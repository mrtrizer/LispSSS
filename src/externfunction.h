#ifndef EXTERNFUNCTION_H
#define EXTERNFUNCTION_H

#include "function.h"
#include <ffi.h>

#include <vector>

class LispExecuter;
class Stack;

///@brief This is an argument for an extern function. You have to fill it before creating an external function.
class ArgumentName
{
public:
    ArgumentName(std::string name, ffi_type * type):name(name),type(type){}
    std::string getName() const {return name;}
    ffi_type * getType() const {return type;}
private:
    std::string name;
    ffi_type * type;
};

class ExternFunction : public Function
{
public:
    ExternFunction(std::vector<ArgumentName> argNames, void(*func)(void), ffi_type * returnType);
    std::string toString() const {return "Extern function";}
private:
    virtual Result run_(const Arguments &arguments, Memory *stack) const;
    ///@brief Converts ffi_type into a lisp type. No any operations with a memory.
    Data::DataType toLispType(ffi_type * type) const;
    ///@brief Converts data from the byte array cData with the type sourceCType to the lisp data format.
    ///@details Warning! If sourceCType is a pointer than the function will mean that the returning
    /// data is a string and it will be deleted after Data object creating.
    Data * convertToLispType(ffi_type * sourceCType,char * cData) const;
    ///@brief Converts data from lispData to cData with targetCType
    void convertToCType(const Data *lispData, ffi_type * targetCType, char *cData, std::list<char *> & strArgs) const;
    ///@brief The list of argument names with data type.
    std::vector<ArgumentName> argNames;
    ///@brief The target extern function
    void (* func)(void);
    ///@brief The return type in ffi format
    ffi_type * returnType;
    ///@brief This flag is true if user wants give current stack pointer as the last argument of the function
    bool giveStackPointer;
};

#endif // EXTERNFUNCTION_H
