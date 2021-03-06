#include <iostream>
#include <string>
#include "parser.hpp"
#include "variable.hpp"
#include "function.hpp"
#include "global.hpp"

using namespace std;

//Create ast node tree and stack
vector<Node*> Parser::program(void){
    vector<Node*> nodes;

    nodes.push_back(binexpr(get_node()));

    while(consume("\n")){
        nodes.push_back(binexpr(get_node()));
    } 
    

    return nodes;
    
}

//classify the token
Node* Parser::primary(void){
    
    count++;
    switch (token->token)
    {
    case T_IDENT:
        return identifier();
    case T_RESERVED:
        return operation_eval();
    case T_NUM:
        return number_eval();
    case T_EOF:
        return 0;
    default:
        cerr << "Error : Unkown token "<< token->str<<endl;
        exit(1);
    }

}

//Create node leaf
Node* Parser::identifier(void)
{
    Node* n;

    if(T_IDENT !=token->token){
        cerr << "Error : expect identifier"<<endl;
        exit(1);
    }

    if(token[1].str == "="){
    
    }

    n = new Node(token->str);
    token++;
    return n;
    
}
//Evaluate operation node
Node* Parser::operation_eval(void)
{
    Node* n;
    
    if(token->str == "("){
        expect("(");
        n=binexpr(static_cast<int>(get_node()));
        expect(")");
        return n;

    }
    n = new Node(get_node());
    token++;
    return n;

}
//Create figure node leaf
Node* Parser:: number_eval(void)
{
    Node* n;
    if(T_NUM !=token->token){
        cerr << "Error : expect number"<<endl;
        exit(1);
    }
    try{
        n = new Node(stoi(token->str));
    }
    catch(const invalid_argument& e){
        cerr<<"Error : Invalid argument. "<<endl;
        exit(1);
    }
    catch(const out_of_range& e){
        cerr<<"Error : Out of range \""<<token->str<<"\""<<endl;
        exit(1);
    }
    
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

//List of nodes precedence
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

//Get node precedence
static int op_precedence(int tokentype){
    int prec;
    prec = OpPrec[tokentype];

    return prec;
}

//Get token and return node type
NodeKind Parser::get_node(void)
{
    NodeKind nodetype;
    int length = sizeof(symbols)/sizeof(*symbols); //length = 22

    switch (token->token)
    {
    //Number node
    case T_NUM:
        return (NodeKind)2;
    //Identifer node
    case T_IDENT:
        return (NodeKind)1;
    //Operation node
    case T_RESERVED:
        for(int i=0;i < length;i++){
            if(token->str == symbols[i]){
                nodetype = (NodeKind)(i+3);
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

//Create main ast tree
Node* Parser::binexpr(int ptp)
{
    Node *left,*right;
    NodeKind tokentype;
    left = primary();
    
    tokentype = get_node();
    //Return if the tokentype is equal to ),],} 
    if(tokentype == ND_RPAREN || tokentype == ND_RBLOCK|| tokentype == ND_RDIC)
        return left; 
    //if the current token is highly prioritized than the prior one.
    while (op_precedence(static_cast<int>(tokentype)) > ptp)
    {
        token++;
        //Get right and left node tree
        right = binexpr(OpPrec[tokentype]);
        left = new Node(tokentype,left,right);
        

        tokentype = get_node();
        //Return if the tokentype is equal to ),],} 
        if(tokentype == ND_RPAREN || tokentype == ND_RBLOCK|| tokentype == ND_RDIC)
            return left;
        
    }
    return left;
    
     
}
//Evaluate if the program should keep creating ast tree or not
bool Parser::consume(string str)
{
    if(T_EOF == token->token) return false;

    if(str == token->str){
        token++;
        return true;
    }
    return false;
}
//Return ast trees if this program process tokens correctly
vector <Node*> Parser::parse(vector<Token> &tokens){

    token = tokens.begin();
    count = 0;
    vector<Node*> nodes = program();

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