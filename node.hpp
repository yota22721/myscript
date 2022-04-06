#ifndef _NODE_HPP_
#define _NODE_HPP_
#include <string>
using namespace std;

typedef enum{
    ND_EOF,
    ND_IDENT,ND_NUM,                                         //identifer,number
    
    ND_ASSIGN,                                               // =
    ND_AND,ND_OR,                                            // &&, ||
    ND_NEAQ,ND_EAQ,                                          // !=, ==
    ND_LESS,ND_LESS_EQ,ND_MORE,ND_MORE_EQ,                   //<, <=, >, >=
    ND_RSHIFT,ND_LSHIFT,                                     //<<,>>
    ND_ADD,ND_MIN,                                           //+,-
    ND_MUL,ND_DIV,ND_PER,                                    // *, /, %
    ND_EXCM,                                                 //!
    ND_RPAREN,ND_LPAREN,ND_LDIC,ND_RDIC,ND_RBLOCK,ND_LBLOCK, // (, ), [, ], {, },  
    
}NodeKind;

class Node{
public:
        NodeKind op;
        Node *left;
        Node *right;
        int intvalue;
        string name;

        void print(void);
        Node (string str);
        Node(NodeKind kind);
        Node(int val);
        Node(NodeKind op,Node *left,Node *right);
        
    
        

};
#endif