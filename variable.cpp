#include "variable.hpp"

//Register the variable name.
Variable::Variable(string name,int offset){
    this->name = name;
    this->offset = offset;
}