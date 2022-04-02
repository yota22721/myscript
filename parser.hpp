#include "node.hpp"
#include "token.hpp"
#include <vector>

using namespace std;
class Parser
{
private:
         vector<Token>::iterator token;
         vector<Node*> program(void);
         Node* indent(void);
         Node* token_type(void);

public:
        vector<Node*> parse(vector<Token>& tokens);
};
