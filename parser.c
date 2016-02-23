#include "parser.h"

void statement(void){
	token tok = next_token();
	printf("\nHOLA ESTOY EN EL PARSER.C\n");
	switch(tok){
		case ID:
			match(ID); match(ASSIGNOP); match(SEMICOLON);
			break;
		case READ:
			break;
		case WRITE:
			break;
		default:
			sintax_error(tok);
			break;
	}
}

token next_token(void){
	token t;
	return t;
}

void match(token t){

}

void sintax_error(token t){

}