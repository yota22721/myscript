#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

using namespace std;

typedef enum {
    T_NUM,      //int value
    T_RESERVED, //symbols
    T_IDENT,    //identifier
    T_EOF,      //end token
}TokenKind;


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

//token

class Token{

public:
        TokenKind token;
        string  str;
        int line;
        int space;
        bool line_end;

        Token(TokenKind token,const char* p,int len);
        Token(TokenKind token,const char* p,int len,int line);
        Token(TokenKind token,const char* p,int len,int line,int space);
        void print(void);
};




#endif