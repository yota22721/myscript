#include <iostream>
#include <cstdlib>
#include <cctype>
#include<cstring>
#include<vector>
#include "tokenizer.hpp"


using namespace std;


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
            if(isFirstToken()){
                Token Token(T_RESERVED,p,len,line,indent);
                tokens.push_back(Token);
            }else{
                Token Token(T_RESERVED,p,len,line);
                tokens.push_back(Token);
        }       
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
            if(isFirstToken()){
                Token Token(T_IDENT,p,len,line,indent);
                tokens.push_back(Token);
            }else{
                Token Token(T_IDENT,p,len,line);
                tokens.push_back(Token);
        }
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
        if(isFirstToken()){
            Token Token(T_IDENT,p,len,line,indent);
            tokens.push_back(Token);
        }else{
            Token Token(T_IDENT,p,len,line);
            tokens.push_back(Token);
        }
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
        if(isFirstToken()){
            Token Token(T_NUM,p,len,line,indent);
            tokens.push_back(Token);
        }else{
            Token Token(T_NUM,p,len,line);
            tokens.push_back(Token);
        }
        
        return true;
    }
    return false;
}

bool Tokenizer::isFirstToken(void){
    char* p =cursor;
    int len;
    for(len =1;isspace(*(cursor-len));len++){
        if(*(cursor-len) == '\n'){
            return true;
        }
    }
    return false;

}

bool Tokenizer::isNewLine(void)
{
    char* p =cursor;

    if (*cursor == '\n'){
        if(tokens.size() != 0 && tokens.back().str != "\n"){
            Token Token(T_RESERVED,cursor,1);
            tokens.push_back(Token);
        }
        //tokens.back().line_end = true;
        cursor++;
        line++;
        return true;
    }else{
        return false;
    }


}

void Tokenizer::skip(void)
{
    indent =0;
    int len =0;
    while((*(cursor+len) !='\n') && isspace(*(cursor+len)) ){
        len++;
    }
    
    if(*(cursor-1) == '\n'){
        indent +=len;
        cursor +=len;
        
    }else{
        cursor +=len;
    }
}


vector<Token> Tokenizer::tokenize(const char* input)
{
    cursor = (char*)input;
    line = 1;
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
    if(tokens.back().str == "\n"){
        tokens.pop_back();
    }
    tokens.push_back(Token(T_EOF,cursor,0));

    cout << string(30,'-')<<endl;
    for(Token token:tokens) token.print();
    cout << string(30,'-')<<endl;
    

    return tokens;
}

