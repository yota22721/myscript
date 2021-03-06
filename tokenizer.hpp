#ifndef _TOKENIZER_HPP_
#define _TOKENIZER_HPP_
#include <vector>
#include "token.hpp"

using namespace std;

//Tokenizer class
class Tokenizer
{

private:
            char* cursor;
            vector<Token> tokens;

public:
            vector<Token> tokenize(const char* input);
            void skip(void);
            bool isNumber(void);
            bool isAlnum(char c);
            bool isIdentifier(void);
            bool isSymbol(void);
            bool isNewLine(void);
            bool isKeyword(void);
            

};
#endif
