#include "function.hpp"
using namespace std;
//Add var in the funcion
void Function::FuncAddVar(string name){
    Variable* var  = new Variable(name,fnc_vars.size());
    fnc_vars.push_back(var);
}