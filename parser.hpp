#include "node.hpp"
#include "token.hpp"
#include <vector>

using namespace std;
class Parser
{
private:
         vector<Token>::iterator token;
         vector<Node*> nodes;

public:
        vector<Node*> parse(vector<Token>& tokens);
};
