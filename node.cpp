#include <iostream>
#include <map>
#include "node.hpp"

using namespace std;

map<NodeKind,string> prinTb1 ={
    {ND_ADD,"+"},
    {ND_MIN,"-"},
    {ND_MUL,"*"},
    {ND_DIV,"/"},
    {ND_EAQ,"="},
    {ND_LPAREN,"("},
    {ND_RPAREN,")"},

};

void Node::node_valuable(NodeKind token,string name){
    op = token;
    this->name = name;
}

void Node::print(void){
    cout << "This is node"<<prinTb1[op] <<endl;
}



