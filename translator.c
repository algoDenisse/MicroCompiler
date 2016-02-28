/*Rutinas Semanticas*/
#include <stdio.h>
#include "translator.h"

char *symbols[9]={
	
};

void start(void){
	/*Semantic Initialization , none needed*/
	printf("%s\n",symbols[1] );
}

void finish(void){
	generate("Halt","","","");
}

// void assign(expr_rec target,expr_rec source){
// 	generate("Store", extract(source),target.name,"");
// }
// op_rec process_op(void){
// 	printf("%s\n","Hola Entre al Translator" );
// 	/*Produce operator descriptor*/
// 	op_rec o;
// 	if(current_token == PLUSOP)
// 		o.operator = PLUS;
// 	else
// 		o.operator=MINUS;
// 	return o;
// }

// expr_rec gen_infix(expr_rec e1,op_rec op,expr_rec e2){
// 	expr_rec e_rec;
// 	/*An expr_rec with temp variant set*/
// 	e_rec.kind = TEMPEXPR;
// 	/*Generate code for infix operation
// 	*Get result temp set and set up semantic record 
// 	*for result
// 	*/
// 	strcpy(erec.name,get_temp());
// 	generate(extract(op),extract(e1),extract(e2),erac.name);
// 	return erec;

// }
// void read_id(expr_rec in_var){
// 	generate("READ",in_var.name,"INTEGER","");
// }

// expr_rec process_id(void){
// 	expr_rec t;
// 	/*Declare id and build a 
// 	*corresponding semantic record
// 	*/
// 	check_id(token_buffer);
// 	t.kind = IDEXPR;
// 	strcpy(t.name,token_buffer);
// 	return t;

// }
// expr_rec process_literal(void){
// 	expr_rec t;
// 	/*
// 	* Covert literal to a numeric representation
// 	*and build semantic record
// 	*/
// 	t.kind =LITERALEXPR;
// 	(void) sscanf(token_buffer,"%d",& t.val);
// 	return t;
// }
// void write_expr(expr_rec out_expr){
// 	generate("Write",extract(out_expr),"Integer","");

// }


void generate(){


}

void extract(){
	
}