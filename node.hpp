#include <string>
using namespace std;

typedef enum{
    ND_ADD,ND_MIN,ND_MUL,ND_DIV,ND_EAQ,
    ND_NUM,ND_INDIET,ND_RPAREN,ND_LPAREN,ND_RBLOCK,ND_LBLOCK
}NodeKind;

class Node{
public:
        NodeKind op;
        Node *left;
        Node *right;
        int intvalue;
        string name;

        void print(void);
        void node_valuable(NodeKind token,string str);
        

};