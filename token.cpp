#include <iostream>
#include <map>
#include <string>
#include "token.hpp"

using namespace std;


static map<TokenKind,string>printTb1 = {
    {T_NUM,"NUM"},
    {T_RESERVED,"RESV"},
    {T_IDENT,"INDENT"},
    {T_EOF,"EOF"},
    
};


Token::Token(TokenKind token,const char* p,int len){
    this->token = token;
    str = string(p,len);

};

void Token::print(void)
{
    cout << printTb1[token]<<"\t" << "\"" <<str<< "\"" <<endl;
};


