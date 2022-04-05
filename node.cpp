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

Node::Node(string name){
    this->op = ND_IDENT;
    this->name = name;
}
Node::Node(string name){
    this->op = ND_IDENT;
    this->name = name;
}

Node::Node(NodeKind kind){
    this->op = kind;
}

Node::Node(int val){
    this->op = ND_NUM;
    this->intvalue = val;
}

Node::Node(NodeKind kind,Node *left,Node *right){
    this->op = kind;
    this->left = left;
    this->right = right;
}

void Node::print(void){
    cout << "This is node"<<prinTb1[op] <<endl;
}



