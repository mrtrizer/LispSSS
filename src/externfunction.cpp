#include "externfunction.h"
#include "atomnildata.h"
#include "atomfloatdata.h"
#include "atomintdata.h"
#include "atomstrdata.h"
#include <ffi.h>
#include <inttypes.h>

#include <string>

#define MAX_STR_SIZE 1000

ExternFunction::ExternFunction(std::vector<ArgumentName> argNames,
                               void(*func)(void), ffi_type * returnType):Function(SUBR,argNames.size())
{
    this->argNames = argNames;
    this->func = func;
    this->returnType = returnType;
}

Data::DataType ExternFunction::toLispType(ffi_type * type) const
{
    if ((type == &ffi_type_float) ||
        (type == &ffi_type_double))
        return Data::ATOM_FLOAT;
    if ((type == &ffi_type_sint8) ||
        (type == &ffi_type_sint16)||
        (type == &ffi_type_sint32)||
        (type == &ffi_type_sint64)||
        (type == &ffi_type_uint8) ||
        (type == &ffi_type_uint16)||
        (type == &ffi_type_uint32)||
        (type == &ffi_type_uint64))
        return Data::ATOM_INT;
    if ((type == &ffi_type_pointer))
        return Data::ATOM_STR;
    ERROR_MESSAGE("Unknown type");
}

void ExternFunction::convertToCType(const Data * lispData, ffi_type * targetCType,char * cData, std::list<char *> & strArgs) const
{
    if (lispData->getDataType() == Data::ATOM_FLOAT)
    {
        AtomFloatData * lispFloat = (AtomFloatData *)lispData;
        if (targetCType == &ffi_type_float)
        {
            *((float *)cData) = (float)lispFloat->getNum();
            return;
        }
        if (targetCType == &ffi_type_double)
        {
            *((double *)cData) = (double)lispFloat->getNum();
            return;
        }
    }
    if (lispData->getDataType() == Data::ATOM_INT)
    {
        AtomIntData * lispInt = (AtomIntData *)lispData;
        if (targetCType == &ffi_type_sint8)
        {
            *((int8_t *)cData) = (int8_t)lispInt->getNum();
            return;
        }
        if (targetCType == &ffi_type_sint16)
        {
            *((int16_t *)cData) = (int16_t)lispInt->getNum();
            return;
        }
        if (targetCType == &ffi_type_sint32)
        {
            *((int32_t *)cData) = (int32_t)lispInt->getNum();
            return;
        }
        if (targetCType == &ffi_type_sint64)
        {
            *((int64_t *)cData) = (int64_t)lispInt->getNum();
            return;
        }
        if (targetCType == &ffi_type_uint8)
        {
            *((uint8_t *)cData) = (uint8_t)lispInt->getNum();
            return;
        }
        if (targetCType == &ffi_type_uint16)
        {
            *((uint16_t *)cData) = (uint16_t)lispInt->getNum();
            return;
        }
        if (targetCType == &ffi_type_uint32)
        {
            *((uint32_t *)cData) = (uint32_t)lispInt->getNum();
            return;
        }
        if (targetCType == &ffi_type_uint64)
        {
            *((uint64_t *)cData) = (uint64_t)lispInt->getNum();
            return;
        }
    }
    if (lispData->getDataType() == Data::ATOM_STR)
        if (targetCType == &ffi_type_pointer)
        {
            char * str = new char[MAX_STR_SIZE + 1];
            strArgs.push_back(str);
            int size = ((AtomStrData *)lispData)->getString().size();
            if (size > MAX_STR_SIZE)
                size = MAX_STR_SIZE;
            memccpy(str,((AtomStrData *)lispData)->getString().c_str(),0,size);
            *(char **)cData = str;
            return;
        }
    delete []cData;
    ERROR_MESSAGE("Argumet typecasting error.");
}

Data * ExternFunction::convertToLispType(ffi_type * sourceCType, char * cData) const
{
    Data::DataType dataType = toLispType(sourceCType);
    if (dataType == Data::ATOM_FLOAT)
    {
        if (sourceCType == &ffi_type_float)
            return new AtomFloatData((double)*((float *)cData));
        if (sourceCType == &ffi_type_double)
            return new AtomFloatData((double)*((double *)cData));
    }
    if (dataType == Data::ATOM_INT)
    {
        if (sourceCType == &ffi_type_sint8)
            return new AtomIntData((int)*((int8_t *)cData));
        if (sourceCType == &ffi_type_sint16)
            return new AtomIntData((int)*((int16_t *)cData));
        if (sourceCType == &ffi_type_sint32)
            return new AtomIntData((int)*((int32_t *)cData));
        if (sourceCType == &ffi_type_sint64)
            return new AtomIntData((int)*((int64_t *)cData));
        if (sourceCType == &ffi_type_uint8)
            return new AtomIntData((int)*((uint8_t *)cData));
        if (sourceCType == &ffi_type_uint16)
            return new AtomIntData((int)*((uint16_t *)cData));
        if (sourceCType == &ffi_type_uint32)
            return new AtomIntData((int)*((uint32_t *)cData));
        if (sourceCType == &ffi_type_uint64)
            return new AtomIntData((int)*((uint64_t *)cData));
    }
    if (dataType == Data::ATOM_STR)
        if (sourceCType == &ffi_type_pointer)
        {
            if (*(char **)cData == 0 )
                return new AtomStrData(std::string(""));
            AtomStrData * result = new AtomStrData(std::string(*((char **)cData)));
            //Deleting string
            delete []*((char **)cData);
            return result;
        }
    ERROR_MESSAGE("Return typecasting error.");
    return 0;
}

Result ExternFunction::run_(const Arguments &arguments, Memory *stack) const
{
    (void) stack;

    ffi_cif cif;
    ffi_type *arg_types[argNames.size()];
    char *arg_values[argNames.size()];
    ffi_status status;
    Result result;

    //The list of string arguments. I need it to clean memory after an extern function calling.
    std::list<char *> strArgs;

    if (arguments.size() != argNames.size())
        ERROR_MESSAGE("Extern function needs " + std::to_string(argNames.size()) + " arguments!");

    for (unsigned int i = 0; i < argNames.size();i++)
        arg_values[i] = new char[arguments[i].getData()->getSize()];

    try
    {
        for (unsigned int i = 0; i < argNames.size(); i++)
        {
            if (arguments[i].getData()->getDataType() == toLispType(argNames[i].getType()))
            {
                arg_types[i] = argNames[i].getType();
                convertToCType(arguments[i].getData(),argNames[i].getType(),arg_values[i],strArgs);
            }
            else
                ERROR_MESSAGE("Type error");
        }

        // Prepare the ffi_cif structure.
        if ((status = ffi_prep_cif(&cif, FFI_DEFAULT_ABI, argNames.size(), returnType, arg_types)) != FFI_OK)
            ERROR_MESSAGE("FFI error. Status: " + std::to_string(status));

    }
    catch (Message & e)
    {
        //Deleting arguments
        for (unsigned int i = 0; i < argNames.size(); i++)
            delete [] arg_values[i];
        throw e;
    }

    char callResult[10];

    // Invoke the function.
    ffi_call(&cif, FFI_FN(func), (void*)callResult, (void**)arg_values);

    result = Result(convertToLispType(returnType,(char*)callResult));

    for (unsigned int i = 0; i < argNames.size(); i++)
        delete [] arg_values[i];

    //Clear string arguments. See strArgs and convertToCType.
    while (strArgs.size() > 0)
    {
        delete []strArgs.back();
        strArgs.pop_back();
    }

    return result;
}
