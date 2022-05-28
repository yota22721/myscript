#ifndef _VARIABLE_HPP_
#define _VARIABLE_HPP_
#include <string>
using namespace std;

//Variable class
class Variable{
public:
    string name;
    int offset;
    Variable(string name,int offset);

};
#endif