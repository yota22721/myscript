#ifndef _PARSER_HPP_
#define _PARSER_HPP_
#include "node.hpp"
#include "token.hpp"
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
         Node* binexpr(int ptp);
         NodeKind get_node(void);
         bool consume(string str);
         void expect(string str);
         int count;

public:
        vector<Node*> parse(vector<Token>& tokens);
};

#endif
