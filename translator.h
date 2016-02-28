#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#endif

#include <stdio.h>
//Semanctic Records for micro grammar symbols
//Almacenan informacion apropiada para un simbolo 

#define MAXIDLEN 33
typedef char string[MAXIDLEN];

/*for operators*/
typedef struct operator {
	enum op {PLUS,MINUS} operator;
} op_rec;

/*expression types*/
enum expr{IDEXPR,LITERALEXPR,TEMPEXPR};

/*for <primary> and <expression>*/
typedef struct expression{
	enum expr kind;
	union{
		string name; /*for IDEXPR,TEMPEXPR*/
		int val; /*for LITERALEXPR*/

	};
}expr_rec;

/*---------------Definicion de Rutinas Semanticas------------*/

char *symbols[9];
void start();
void finish();
void assign(expr_rec target,expr_rec source);
op_rec process_op();
expr_rec gen_infix(expr_rec e1,op_rec op,expr_rec e2);
void read_id(expr_rec in_var);
expr_rec process_id();
expr_rec process_literal();
void write_expr(expr_rec out_expr);
//void expression(expr_rec *result);


void generate();
void extract();
