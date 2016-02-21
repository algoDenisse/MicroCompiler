#include <stdio.h>
#include <ctype.h>

int in_char, c;

/* Can recognize micro identifiers and literals. EOF: end of file*/
(while((in_char = getchar()) != EOF){
	if(isspace(in_char))  /*skips white space*/
		continue; /*do nothing*/
	else if(isalpha(in_char)){ // code to recognize identifiers
		/*
		* ID ::= LETTER | ID LETTER
		*				| ID DIGIT 
		*				| ID UNDERSCORE
		*/

		for ( c= getchar();isalnum(c) || c=='_'; c = getchar())
			;
		ungetc(c,stdin);

		return ID;
	}else if (isdigit(in_char)){ // code to recognize int literals
		/*
		* INTLITERAL ::= DIGIT|
		*				 INTLITERAL DIGIT
		*/
		while (isdigit((c = getchar())))
			;
		ungetc(c,stdin);
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
		/* looking for --,comment star*/
		c = getchar();
		if(c == '-'){
			while ((in_char = getchar()) != '\n');
		} else {
			ungetc(c,stdin);
			return MINUSOP;
		}

	}else
		lexical_error(in_char); //cannot begin any token 


}