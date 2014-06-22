#ifndef FUNCCONTROLLER_H
#define FUNCCONTROLLER_H

#include <string>
#include <map>

class Function;
class LispExecuter;

class FuncController
{
public:
    FuncController(LispExecuter * executer, std::ostream *out, std::istream *in);
    ///@brief Adds or Redefines function
    void setFunction(Function *function);
    ///@brief Returns function with name
    Function *getFunction(std::string name);

private:
    typedef std::map<std::string, Function *> FunctionMap;
    typedef std::pair<std::string, Function *> FunctionItem;
    FunctionMap functions;
    std::ostream * out;
    std::istream * in;
    LispExecuter *executer;
};

#endif // FUNCCONTROLLER_H
