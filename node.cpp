#include <iostream>
#include <map>
#include "node.hpp"

using namespace std;


//prinTb1 is token's dict for debug
map<NodeKind,string> prinTb1 ={
    {ND_ADD,"+"},
    {ND_MIN,"-"},
    {ND_MUL,"*"},
    {ND_DIV,"/"},
    {ND_ASSIGN,"="},
    {ND_LPAREN,"("},
    {ND_RPAREN,")"},

};

//Create identifer(ex: function name, variable name, string value..) node 
Node::Node(string name){
    this->op = ND_IDENT;
    this->name = name;
}

//Create operation leaf
Node::Node(NodeKind kind){
    this->op = kind;
}
//Create figure node
Node::Node(int val){
    this->op = ND_NUM;
    this->intvalue = val;
}

//Create node tree
Node::Node(NodeKind kind,Node *left,Node *right){
    this->op = kind;
    this->left = left;
    this->right = right;
}


//Output parsed tokens
//This function is used for debug
void Node::print(void)
{
    switch (this->op)
    {
    case ND_NUM:
        cout << this->intvalue;
        return;
    case ND_IDENT:
        cout << this->name;
        return;
    default:
        break;
    }

    cout << "( "<<prinTb1[op] << " ";

    if(left){
        left->print();
    }
    else{
        cout <<"_";
    }
    cout <<" ";

    if(right){
        right->print();
    }
    else{
        cout <<"_";
    }
    cout << " )";

}



