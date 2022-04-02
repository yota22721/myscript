#include <iostream>
#include <string>
#include "parser.hpp"


using namespace std;

vector<Node*> Parser::program(void){
    vector<Node*> nodes;
    token_type();

}

Node* Parser::token_type(void){
    switch (token->token)
    {
    case T_IDENT:
        /* code */
        break;
    
    default:
        break;
    }

}

vector <Node*> Parser::parse(vector<Token> &tokens){

    token = tokens.begin();
    vector<Node*> nodes = program();

    if(token->token != T_EOF){
        cerr << "Failed to parse"<<endl;
        exit(1);
    }

    return nodes;

}