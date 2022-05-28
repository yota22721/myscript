#include <iostream>
#include <map>
#include <string>
#include "token.hpp"

using namespace std;

//printTb1 is token's dict for debug
static map<TokenKind,string>printTb1 = {
    {T_NUM,"NUM"},
    {T_RESERVED,"RESV"},
    {T_IDENT,"IDENT"},
    {T_EOF,"EOF"},
    
};
//classify the token type
Token::Token(TokenKind token,const char* p,int len){
    this->token = token;
    str = string(p,len);

};
//Output the information of tokens 
//This function is used for debug
void Token::print(void)
{
    cout << printTb1[token]<<"\t" << "\"" <<str<< "\"" <<endl;
};


