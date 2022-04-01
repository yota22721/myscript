#include <iostream>
#include <cstdlib>
#include <cctype>
#include<cstring>
#include<vector>
#include "tokenizer.hpp"

using namespace std;

static const char* symbols[] ={"+","-","*","/","(",")","{","}","="};
static const char* keywords[] ={"if","else","for","while","return"};


bool Tokenizer::isAlnum(char c)
{
    if(isalnum(c) || c == '_'){
        return true;
    }else{
        return false;
    }
    
}

bool Tokenizer::isSymbol(void)
{
    char* p = cursor;
 
    for(const char* symbol:symbols){
        int len =strlen(symbol);

        if(memcmp(cursor,symbol,len) == 0){
            Token Token(T_RESERVED,p,len);
            tokens.push_back(Token);
            cursor +=len;
            return true;
        }
    }
    return false;


}

bool Tokenizer::isKeyword(void)
{
    char* p =cursor;

    for(const char* keyword: keywords){
        int len = strlen(keyword);

        if(memcmp(cursor,keyword,len) == 0 && isAlnum(*(cursor+len))){
            Token Token(T_RESERVED,p,len);
            tokens.push_back(Token);
            cursor +=len;
            return true;
        }
    }
    return false;
}


bool Tokenizer::isIdentifier(void)
{
    char* p = cursor;
    int len = 0;

    for(;isAlnum(*cursor);cursor++) len++;
    
    if(len > 0){
        Token Token(T_IDENT,p,len);
        tokens.push_back(Token);
        return true;
    }
    return false;
}


bool Tokenizer::isNumber(void)
{
    char* p =cursor;
    int len =0;
    

    for(;isdigit(*cursor);cursor++) len++;

    if(len>0){
        Token Token(T_NUM,p,len);
        tokens.push_back(Token);
        return true;
    }
    return false;
}

bool Tokenizer::isNewLine(void)
{
    char* p =cursor;
    if (*cursor == '\n'){
        cursor++;
        return true;
    }else{
        return false;
    }


}

void Tokenizer::skip(void)
{
    while((*cursor !='\n') && isspace(*cursor) ){
        cursor++;
    }
    
}


vector<Token> Tokenizer::tokenize(const char* input)
{
    cursor = (char*)input;
    tokens.clear();
    

    while(*cursor){
            skip();
            if(isSymbol()){

            }else if(isKeyword()){
                
            }else if(isNumber()){

            }else if(isIdentifier()){

            }else if(isNewLine()){

            }else{
                cerr << "Error : invalid character "<< *cursor<<endl;
                exit(1);
            }            

    }
    cout << string(30,'-')<<endl;
    for(Token token:tokens) token.print();
    cout << string(30,'-')<<endl;
    

    return tokens;
}

