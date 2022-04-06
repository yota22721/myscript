#include <iostream>
#include <string>
#include "parser.hpp"


using namespace std;

vector<Node*> Parser::program(void){
    vector<Node*> nodes;
    while(token->token){
        
        nodes.push_back(expression(get_node()));
    }
    return nodes;
    
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
    if(T_IDENT !=token->token){
        cerr << "Error : expect identifier"<<endl;
        exit(1);
    }
    n = new Node(token->str);
    token++;
    return n;
    
}

Node* Parser::operation_eval(void)
{
    Node* n;

    cout << "ope token : "<< token->str<<endl;
    
    if(token->str == "("){
        expect("(");
        n=expression(static_cast<int>(get_node()));
        expect(")");
        return n;
        /*
        switch (type)
        {
        case ND_NUM:
            cout << "Number ! "<< token->str<<endl;
            n = new Node(stoi(token->str));
            
            return n;
        case ND_IDENT:
            break;
        default:
            cerr << "Error : incorrect token \""<<token->str<<"\""<<endl;
            exit(1);
        }*/
    }
    n = new Node(get_node());
    cout << "ope  : "<< token->str<<endl;
    token++;
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
    cout << "Number : "<< token->str<<endl;
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
    int length = sizeof(symbols)/sizeof(*symbols); //length = 22

    switch (token->token)
    {
    case T_NUM:
        return (NodeKind)2;
    case T_IDENT:
        cout << "indent token : "<< token->str<<endl;
        return (NodeKind)1;
    case T_RESERVED:
        for(int i=0;i < length;i++){
            if(token->str == symbols[i]){
                nodetype = (NodeKind)(i+3);
                cout << "ope token : "<<token->str<<endl;
                return nodetype;
            }
        }
        return (NodeKind)0;

    case T_EOF:
        return (NodeKind)0;

    default:
        cerr << "Error : unexpected token \""<<token->token<<"\""<<endl;
    
        exit(1);
    }


}


Node* Parser::expression(int ptp)
{
    Node *left,*right;
    NodeKind tokentype;
    left = primary();
    
    tokentype = get_node();
    cout <<"tokentype : " <<tokentype<<endl;
    cout <<"end token"<<token->str<<endl;
    if(tokentype == ND_RPAREN || tokentype == ND_RBLOCK|| tokentype == ND_RDIC)
        
        return left;
    
    

    
    while (op_precedence(static_cast<int>(tokentype)) > ptp)
    {
        token++;
        right = expression(OpPrec[tokentype]);

        left = new Node(tokentype,left,right);
        tokentype = get_node();
        if(tokentype == ND_RPAREN || tokentype == ND_RBLOCK|| tokentype == ND_RDIC)
            return left;
        
    }
    return left;
    
    
}

bool Parser::consume(string str)
{
    if(T_EOF == token->token) return false;

    if(str == token->str){
        token++;
        return true;
    }
    return false;
}

vector <Node*> Parser::parse(vector<Token> &tokens){

    token = tokens.begin();
    vector<Node*> nodes = program();

    cout << "last token : "<<token->token<<endl;
    if(token->token != T_EOF){
        cerr << "Failed to parse"<<endl;
        exit(1);
    }

    cout<< string(30,'-')<<endl;
    for(Node* node:nodes){
        node->print();
        cout << endl;
    }
    cout<< string(30,'-')<<endl;
    return nodes;

}