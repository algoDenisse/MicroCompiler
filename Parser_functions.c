void system_goal(void){
	/*<system goal> ::= <program> SCANEOF*/
	program();

	//macth() debe llamar al scanner para obtener el sig
	//token . Si todo correcto guarda en variable global current_token
	match(SCANEOF);
}

//FOR PROGRAM

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
	while(TRUE){
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
	token tok= next_token();

	switch(tok){
		case ID:
			/*<statement> ::= ID := <expresion>;*/
			match(ID);match(ASSIGNOP);
			expresion();match(SEMICOLON);
			break;
		case READ:
		/*<statement> ::= READ(<id_list>);*/
			match(READ);match(LPAREN);
			id_list();match(RPAREN);
			match(SEMICOLON);
			break;
		case WRITE:
		/*<statement>::= WRITE(<expr list>);*/
			match(WRITE);match(LPAREN);
			expr_list();match(RPAREN);
			match(SEMICOLON);
			break;
		default:
			sintax_error(tok);
			break;

	}
}

void id_list(void){
	/* <id_list> ::= ID{ ,ID}*/
	match();
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
	for(t=next_token();t==PLUSOP || t==MINUSOP; t=next_token()){
		add_op();
		primary();
	}

}
void expr_list(void){
	/*<expr list>::=<expresion>{ ,<expresion>]*/
	expresion();
	while(next_token() == COMMA){
		match(COMMA);
		expresion();
	}
}
void add_op(void){
	token tok = next_token();
	/*<addop>::PLUSOP | MINUSOP*/
	if(tok == PLUSOP || tok==MINUSOP)
		match(tok);
	else
		sintax_error(tok);
}
void primary(void){
	token tok=next_token();
	switch(tok){
		case LPAREN:
			/*<primary>::= {<expresion>}*/
			match(LPAREN); expresion();
			match(RPAREN);
			break;
		case ID:
			/*<primary>::= ID*/
			match(ID);
			break;
		case INTLITERAL:
			/*<primary>::=INTLITERAL*/
			match(INTLITERAL);
			break:
		default:
			sintax_error(tok);
			break;


	}
}