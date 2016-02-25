#include "parser.h"


token next_token(void){
	nextev_token= scanner();
	if (nextev_token == -1) nextev_token = scanner();
	printf("\nNext token a evaluar: %d\n", nextev_token); 
	return nextev_token;

}

void match(token t){
	
	if(current_token == t){
		printf("SI Matcheo!\n");
		current_token = next_token();
	}
	else{
		sintax_error(t);
		
	}

}

void sintax_error(token t){
	// revisar que se esperaba 
	//Condicionales de acuerdo al token 
	//Si id , esperaba .... 

	printf("Sintax error, expecting %s\n",get_token_name(t));
	exit(0);
}

/*________________FUNCIONES PRINCIPALES DEL PARSER______-*/
void system_goal(void){
	/*<system goal> ::= <program> SCANEOF*/
	program();

	//macth() debe llamar al scanner para obtener el sig
	//token . Si todo correcto guarda en variable global current_token
	match(SCANEOF);

}

void program(void){
	/* <program> ::= BEGIN <statement list> END*/
	match(BEGIN);
	statement_list();
	match(END);
}


void statement_list(void){
	/*
	*<statement list> ::= <statement>{<statement>}*/
	statement();
	while(true){
		switch(next_token()){
			case ID:
			case READ:
			case WRITE:
				statement();
				break;
			default:
				return;
		}
	}
}

void statement(void){
	token tok= current_token;

	switch(tok){
		case ID:
			/*<statement> ::= ID := <expresion>;*/
			match(ID);match(ASSIGNOP);
			expression();
			match(SEMICOLON);
			
			break;
		case READ:
		/*<statement> ::= READ(<id_list>);*/
			// match(READ);match(LPAREN);
			// id_list();match(RPAREN);
			// match(SEMICOLON);
			printf("\nSoy Read!\n");
			break;
		case WRITE:
		/*<statement>::= WRITE(<expr list>);*/
			// match(WRITE);match(LPAREN);
			// expr_list();match(RPAREN);
			// match(SEMICOLON);
		    printf("\nSoy WRITE!\n");
			break;
		default:
			sintax_error(tok);
			break;

	}
}

void id_list(void){
	/* <id_list> ::= ID{ ,ID}*/
	match(ID);
	while(next_token() == COMMA){
		match(COMMA);
		match(ID);

	}
}

void expression(void){
	token t;
	/*
	* <expresion> ::= <primary>
	*				{<add op><primary>}
	*/
	primary();
	for(t=current_token;t==PLUSOP || t==MINUSOP; t=next_token()){
		add_op();
		primary();
	}

}
void expr_list(void){
	/*<expr list>::=<expresion>{ ,<expresion>]*/
	expression();
	while(next_token() == COMMA){
		match(COMMA);
		expression();
	}
}
void add_op(void){
	token tok = current_token;
	/*<addop>::PLUSOP | MINUSOP*/
	if(tok == PLUSOP || tok==MINUSOP)
		match(tok);
	else
		sintax_error(tok);
}
void primary(void){
	token tok= current_token;
	switch(tok){
		case LPAREN:
			/*<primary>::= {<expresion>}*/
			match(LPAREN); expression();
			match(RPAREN);
			break;
		case ID:
			/*<primary>::= ID*/
			match(ID);
			break;
		case INTLITERAL:
			/*<primary>::=INTLITERAL*/
			match(INTLITERAL);
			break;
		default:
			sintax_error(tok);
			break;


	}
}

const char * get_token_name(token t){
	switch(t){
		case BEGIN:
			return "BEGIN";
		case END:
			return "END";
		case READ:
			return "READ";
		case WRITE:
			return "WRITE";
		case ID:
			return "ID";
		case INTLITERAL:
			return "INTLITERAL";
		case LPAREN:
			return "LPAREN";
		case RPAREN:
			return "RPAREN";
		case SEMICOLON:
			return "SEMICOLON";
		case COMMA:
			return "COMMA";
		case ASSIGNOP:
			return "ASSIGNOP";
		case PLUSOP:
			return "PLUSOP";
		case MINUSOP:
			return "MINUSOP";
		case SCANEOF:
			return "SCANEOF";
	}
}