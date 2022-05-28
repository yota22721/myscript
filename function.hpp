#ifndef _FUNCTION_HPP_
#define _FUNCTION_HPP_
#include <vector>
#include<string>
#include "variable.hpp"
using namespace std;

//Function class
class Function{
private:

public:
        string name;
        vector<Variable*> fnc_vars;
     
        void FuncAddVar(string name);


};

#endif