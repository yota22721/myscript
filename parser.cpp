#include <iostream>
#include <string>
#include "parser.hpp"


using namespace std;

vector<Node*> Parser::program(void){
    vector<Node*> nodes;
    while(1){
        
    }
    
}


Node* Parser::primary(void){
    
    switch (token->token)
    {
    case T_IDENT:
        return indentifier();
    case T_RESERVED:
        return operation_eval();
    case T_NUM:
        return number_eval();
    default:
        cerr << "Error : Unkown token "<< token->str<<endl;
        exit(1);
    }

}

Node* Parser::indentifier(void)
{
    Node* n;
    int len =0;

    //n = n.node_ident(token->str);
    n = new Node(token->str);
    token++;
    return n;
    
}

Node* Parser::operation_eval(void)
{
    Node* n;
    expect("(");
    n = expression(ND_NUM);
    expect(")");

    return n;

}

Node* Parser:: number_eval(void)
{
    Node* n;
    if(T_NUM !=token->token){
        cerr << "Error : expect number"<<endl;
        exit(1);
    }
    n = new Node(stoi(token->str));
    token++;
    return n;
}

void Parser::expect(string str)
{
    if(T_EOF == token->token || str != token->str ){
        cerr << "Error : expect \""<< str<<"\""<<endl;
        exit(1);
    }else{
        token++;
    }

}


static int OpPrec[] =
 {0,
  5,5,
  
  20,
  30,30,
  40,40,
  50,50,50,50,
  60,60,
  70,70,
  80,80,80,
  90,
  100,100,100,100,100,100,
};

static int op_precedence(int tokentype){
    int prec;
    prec = OpPrec[tokentype];

    return prec;
}

NodeKind Parser::get_node(void)
{
    NodeKind nodetype;
    int length = sizeof(symbols)/sizeof(*symbols);
     for(int i=0;i < length;i++){
        if(token->str == symbols[i]){
            nodetype = (NodeKind)(i+3);
            return nodetype;
        }else if(token->token == T_NUM){
            nodetype =(NodeKind)2;
            return nodetype;
        }else if(token->token == T_IDENT){
            nodetype =(NodeKind)1;
            return nodetype;
        }
    }
    return (NodeKind)0;

}


Node* Parser::expression(int ptp)
{
    Node *left,*right;
    NodeKind tokentype;
    
    left = primary();
    tokentype = get_node();

    if(tokentype == ND_EOF)
        return left;

    
    while (op_precedence(static_cast<int>(tokentype)) > ptp)
    {
        token++;
        right = expression(OpPrec[tokentype]);

        left = new Node(tokentype,left,right);
        tokentype = get_node();
        if(tokentype == ND_EOF)
            return left;
        
    }
    return left;
    
    
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