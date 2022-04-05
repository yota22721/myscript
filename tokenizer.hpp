#include <vector>
#include "token.hpp"

using namespace std;

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

