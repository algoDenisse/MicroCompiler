#include <stdio.h>
#include <ctype.h>

extern char token_buffer[];

token scanner(void)
{

	int in_char, c;

	clear_buffer();

	if(feof(stdin))
		return SCANEOF;

	/* Can recognize micro identifiers and literals. EOF: end of file*/
	while((in_char = getchar()) != EOF){
		if(isspace(in_char))  /*skips white space*/
			continue; /*do nothing*/
		else if(isalpha(in_char)){ // code to recognize identifiers
			/*
			* ID ::= LETTER | ID LETTER
			*				| ID DIGIT 
			*				| ID UNDERSCORE
			*/
			buffer_char(in_char);
			for ( c= getchar();isalnum(c) || c=='-'; c = getchar())
				buffer_char(c);
			    ungetc(c,stdin);
			    return check_reserved();

			//return ID;
		}else if (isdigit(in_char)){ // code to recognize int literals
			/*
			* INTLITERAL ::= DIGIT|
			*				 INTLITERAL DIGIT
			*/
			buffer_char(in_char);
			for(c=getchar(); isdigit(c);c=getchar())
				buffer_char(c);
			ungetc(c,stdin);

			//while (isdigit((c = getchar())))
				
			//ungetc(c,stdin);
			return INTLITERAL;
		} else if (in_char == '('){
			return LPAREN;

		}else if(in_char == ')'){
			return RPAREN;

		}else if(in_char == ';'){
			return SEMICOLON;

		}else if(in_char == ','){
			return COMMA;

		}else if(in_char == '+'){
			return PLUSOP;


		}else if(in_char == ':'){
			/* looking for ":="*/
			c = getchar();
			if(c == '=')
				return ASSIGNOP;
			else{
				ungetc(c,stdin);
				lexical_error(in_char);
			}

		}else if(in_char == '-'){
			/* looking for --,comment start*/
			c = getchar();
			if(c == '-'){
				do
					in_char=getchar();
				while(in_char != '\n')

				//while ((in_char = getchar()) != '\n');
			} else {
				ungetc(c,stdin);
				return MINUSOP;
			}

		}else
			lexical_error(in_char); //cannot begin any token 


	}

}