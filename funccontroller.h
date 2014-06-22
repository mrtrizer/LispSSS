#ifndef FUNCCONTROLLER_H
#define FUNCCONTROLLER_H

#include <string>
#include <map>

class Function;

class FuncController
{
public:
    FuncController();
    ///@brief Adds or Redefines function
    void setFunction(Function *function);
    ///@brief Returns function with name
    Function *getFunction(std::string name);

private:
    typedef std::map<std::string, Function *> FunctionMap;
    typedef std::pair<std::string, Function *> FunctionItem;
    FunctionMap functions;
};

#endif // FUNCCONTROLLER_H
