#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

using namespace std;

//Token kind
typedef enum {
    T_NUM,      //int value
    T_RESERVED, //symbols
    T_IDENT,    //identifier
    T_EOF,      //end token
}TokenKind;

//Operation list
static const char* symbols[] ={
                               "=",
                               "&&","||",
                               "!=","==",
                               "<","<=",">",">=",
                               "<<",">>",
                               "+","-",
                               "*","/","%",
                               "!",
                               "(",")","[","]","{","}",};

//Token class
class Token{

public:
        TokenKind token;
        string  str;
    
        Token(TokenKind token,const char* p,int len);
        void print(void);
};


#endif 