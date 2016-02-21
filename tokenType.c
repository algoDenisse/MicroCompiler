/*It will represent the set of Micro Tokens*/

typedef enum token_types{

	BEGIN,END,READ,WRITE,ID,INTLITERAL,LPAREN,RPAREN,SEMICOLON,COMMA,
	ASSIGNOP,PLUSOP,MINUSOP,SCANEOF
} token;

/*The fuction produce a stream of token representations*/
extern token scanner(void);