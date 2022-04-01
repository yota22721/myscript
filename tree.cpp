#include "defs.h"
#include "data.h"
#include "decl.h"

//AST tree functions
//Build and return generic ASTnode

struct ASTnode *mkastnode(int op,struct ASTnode *left,
                            struct ASTnode *right,int intvalue){

        struct ASTnode *n;

        n = (struct ASTnode *) malloc(sizeof(struct ASTnode));
        if(n == NULL){
            std::cout << "Unable to malloc in mkastnode()\n";
            exit(1);
        }

        n->op = op;
        n->left = left;
        n->right = right;
        n->intvalue = intvalue;

        return n;
}

//Make an AST leaf node
struct ASTnode *mkastleaf(int op,int intvalue){
    return mkastnode(op,NULL,NULL,intvalue);
}

struct ASTnode *mkastunary(int op,struct ASTnode *left,int intvalue){
    return mkastnode(op,left,NULL,intvalue);
}