#include <iostream>
#include <map>
#include <string>
#include "token.hpp"

using namespace std;


static map<TokenKind,string>printTb1 = {
    {T_NUM,"NUM"},
    {T_RESERVED,"RESV"},
    {T_IDENT,"IDENT"},
    {T_EOF,"EOF"},
    
};

Token::Token(TokenKind token,const char* p,int len){
    this->token = token;
    str = string(p,len);

};

Token::Token(TokenKind token,const char* p,int len,int line){
    this->token = token;
    str = string(p,len);
    this->line = line;

};
Token::Token(TokenKind token,const char* p,int len,int line,int space){
    this->token = token;
    str = string(p,len);
    this->line = line;
    this->space = space;

};

void Token::print(void)
{
    cout << printTb1[token]<<"\t" << "\"" <<str<< "\"" <<endl;
};


