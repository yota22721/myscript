using namespace std;

typedef enum {
    T_NUM,      //int value
    T_RESERVED, //token
    T_IDENT,    //identifier
    T_EOF,      //end
}TokenKind;

//token
/*

typedef enum {
	TK_NUM,			// 数値
	TK_RESERVED,	// 記号
	TK_IDENT,		// 識別子
	TK_EOF,			// 終端
} TokenKind;

*/
class Token{
public:
        TokenKind token;
        string  str;

        Token(TokenKind token,const char* p,int len);
        void print(void);


};