#include "token.hpp"
#include "node.hpp"
#include <vector>

using namespace std;


class Parser
{
private:
         vector<Token>::iterator token;
         vector<Node*> program(void);
         Node* primary(void);
         Node* operation_eval(void);
         Node* indentifier(void);
         Node* number_eval(void);
         Node* expression(int ptp);
         int tokentype(void);
         NodeKind get_node(void);
         void expect(string str);

         
         

public:
        vector<Node*> parse(vector<Token>& tokens);
};


